# Be silent per default, but 'make V=1' will show all compiler calls.
# If you're insane, V=99 will print out all sorts of things.
ifeq ($(V),0)
Q	:= @
NULL	:= 2>/dev/null
endif

# Tool paths.
PREFIX	= arm-none-eabi-
CC	= $(PREFIX)gcc
LD	= $(PREFIX)gcc
OBJCOPY	= $(PREFIX)objcopy
OBJDUMP	= $(PREFIX)objdump
SIZE	:= $(PREFIX)size
OOCD	?= openocd

# Files and build location
BUILD_DIR = $(PROJECT)/build
CFILES = $(wildcard $(PROJECT)/*.c)
OBJS = $(CFILES:$(PROJECT)/%.c=$(BUILD_DIR)/%.o)
OBJS += $(AFILES:%.S=$(BUILD_DIR)/%.o)

# Libopencm3 Includes
OPENCM3_DIR  =	libopencm3
OPENCM3_INC = $(OPENCM3_DIR)/include
INCLUDES += $(patsubst %,-I%, . $(OPENCM3_INC) )

include $(OPENCM3_DIR)/mk/genlink-config.mk

# List of files for make_clean
GENERATED_BINS = $(BUILD_DIR)/*.elf $(BUILD_DIR)/*.bin $(BUILD_DIR)/*.map $(BUILD_DIR)/*.list $(BUILD_DIR)/*.lss

# Options & Flags
OPT ?= -Os
CSTD ?= -std=c99

TGT_CPPFLAGS += -MD
TGT_CPPFLAGS += -Wall -Wundef $(INCLUDES)
TGT_CPPFLAGS += $(INCLUDES) $(OPENCM3_DEFS)

TGT_CFLAGS += $(OPT) $(CSTD) -ggdb3
TGT_CFLAGS += $(ARCH_FLAGS)
TGT_CFLAGS += -fno-common
TGT_CFLAGS += -ffunction-sections -fdata-sections
TGT_CFLAGS += -Wextra -Wshadow -Wno-unused-variable -Wimplicit-function-declaration
TGT_CFLAGS += -Wredundant-decls -Wstrict-prototypes -Wmissing-prototypes

TGT_CXXFLAGS += $(OPT) $(CXXSTD) -ggdb3
TGT_CXXFLAGS += $(ARCH_FLAGS)
TGT_CXXFLAGS += -fno-common
TGT_CXXFLAGS += -ffunction-sections -fdata-sections
TGT_CXXFLAGS += -Wextra -Wshadow -Wredundant-decls  -Weffc++

TGT_ASFLAGS += $(OPT) $(ARCH_FLAGS) -ggdb3

TGT_LDFLAGS += -T$(LDSCRIPT) -L$(OPENCM3_DIR)/lib -nostartfiles
TGT_LDFLAGS += $(ARCH_FLAGS)
TGT_LDFLAGS += -specs=nano.specs
TGT_LDFLAGS += -Wl,--gc-sections

# OPTIONAL
TGT_LDFLAGS += -Wl,-Map=$(BUILD_DIR)/$(PROJECT).map
ifeq ($(V),99)
TGT_LDFLAGS += -Wl,--print-gc-sections
endif

# Linker script generator fills this in for us.
ifeq (,$(DEVICE))
LDLIBS += -l$(OPENCM3_LIB)
endif
# nosys is only in newer gcc-arm-embedded...
#LDLIBS += -specs=nosys.specs
LDLIBS += -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group

print:
	@echo $(GENERATED_BINS)

all: print $(BUILD_DIR)/$(PROJECT).elf $(BUILD_DIR)/$(PROJECT).bin $(BUILD_DIR)/$(PROJECT).lss $(BUILD_DIR)/$(PROJECT).list
	$(SIZE) $(BUILD_DIR)/$(PROJECT).elf


# error if not using linker script generator
ifeq (,$(DEVICE))
$(LDSCRIPT):
ifeq (,$(wildcard $(LDSCRIPT)))
    $(error Unable to find specified linker script: $(LDSCRIPT))
endif
else
# if linker script generator was used, make sure it's cleaned.
GENERATED_BINS += $(LDSCRIPT)
endif

# Need a special rule to have a bin dir
$(BUILD_DIR)/%.o: $(PROJECT)/%.c
	@printf "  CC\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TGT_CFLAGS) $(CFLAGS) $(TGT_CPPFLAGS) $(CPPFLAGS) -o $@.S -E $<
	$(Q)$(CC) $(TGT_CFLAGS) $(CFLAGS) $(TGT_CPPFLAGS) $(CPPFLAGS) -o $@ -c $<


$(BUILD_DIR)/$(PROJECT).elf: $(OBJS) $(LDSCRIPT) $(LIBDEPS)
	@printf "  LD\t$@\n"
	$(Q)$(LD) $(TGT_LDFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

%.bin: %.elf
	@printf "  OBJCOPY\t$@\n"
	$(Q)$(OBJCOPY) -O binary  $< $@

%.lss: %.elf
	$(OBJDUMP) -h -S $< > $@

%.list: %.elf
	$(OBJDUMP) -S $< > $@

clean:
	rm -rf $(BUILD_DIR) $(GENERATED_BINS)

.PHONY: all clean flash
-include $(OBJS:.o=.d)

include $(OPENCM3_DIR)/mk/genlink-rules.mk
