OPT ?= -Os
CSTD ?= -std=c99
BUILD_DIR = ../build

# Be silent per default, but 'make V=1' will show all compiler calls.
# If you're insane, V=99 will print out all sorts of things.
ifeq ($(V),0)
Q	:= @
NULL	:= 2>/dev/null
endif


# Tool paths.
PREFIX	?= ../util/gcc-arm/bin/arm-none-eabi-
CC	= $(PREFIX)gcc
LD	= $(PREFIX)gcc
OBJCOPY	= $(PREFIX)objcopy
OBJDUMP	= $(PREFIX)objdump
SIZE	:= $(PREFIX)size
OOCD	?= openocd

OPENCM3_INC = $(OPENCM3_DIR)/include

# Inclusion of library header files
INCLUDES += $(patsubst %,-I%, . $(OPENCM3_INC) )

OBJS = $(CFILES:%.c=$(BUILD_DIR)/%.o)
OBJS += $(AFILES:%.S=$(BUILD_DIR)/%.o)

# List of files for make_clean
GENERATED_BINS = $(PROJECT)*.elf $(PROJECT)*.bin $(PROJECT)*.map $(PROJECT)*.list $(PROJECT)*.lss

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
TGT_LDFLAGS += -Wl,-Map=$(PROJECT).map
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

# Burn in legacy hell fortran modula pascal yacc idontevenwat
.SUFFIXES:
.SUFFIXES: .c .S .h .o .cxx .elf .bin .list .lss .i

# Bad make, never *ever* try to get a file out of source control by yourself.
%: %,v
%: RCS/%,v
%: RCS/%
%: s.%
%: SCCS/s.%

all: $(PROJECT).elf $(PROJECT).bin $(PROJECT).lss $(PROJECT).list
	$(SIZE) $(PROJECT).elf
flash: $(PROJECT).flash

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
$(BUILD_DIR)/%.o: %.c
	@printf "  CC\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TGT_CFLAGS) $(CFLAGS) $(TGT_CPPFLAGS) $(CPPFLAGS) -o $@.S -E $<
	$(Q)$(CC) $(TGT_CFLAGS) $(CFLAGS) $(TGT_CPPFLAGS) $(CPPFLAGS) -o $@ -c $<

$(BUILD_DIR)/%.o: %.cxx
	@printf "  CXX\t$<\n"
	@mkdir -p $(dir $@)


$(PROJECT).elf: $(OBJS) $(LDSCRIPT) $(LIBDEPS)
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
