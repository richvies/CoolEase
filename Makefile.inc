#############################################################
# Tools
#############################################################

PREFIX		= arm-none-eabi
CC			:= $(PREFIX)-gcc
CXX			:= $(PREFIX)-g++
LD			:= $(PREFIX)-gcc
AR			:= $(PREFIX)-ar
AS			:= $(PREFIX)-as
OBJCOPY		:= $(PREFIX)-objcopy
OBJDUMP		:= $(PREFIX)-objdump
GDB			:= $(PREFIX)-gdb
SIZE		:= $(PREFIX)-size
OOCD		:= openocd

#############################################################
# LibopenCM3
#############################################################

OPENCM3_DIR  	= libopencm3
OPENCM3_INC 	= $(OPENCM3_DIR)/include
INCLUDES 	   += $(patsubst %,-I%, . $(OPENCM3_INC) )

include $(OPENCM3_DIR)/mk/genlink-config.mk

# Linker script generator fills this in for us.
ifeq (,$(DEVICE))
LDLIBS += -l$(OPENCM3_LIB)
endif

LDLIBS += -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group

#############################################################
# General Project Files
#############################################################

# Include Headers
INCLUDES += -I$(PROJECT)/include -Icommon/include

# Source Files
SRCDIR = $(PROJECT)/src
COMDIR = common/src
CFILES = $(wildcard $(SRCDIR)/*.c) $(wildcard $(COMDIR)/*.c)

# Object Files
OBJDIR = $(PROJECT)/obj
OBJS   = $(addprefix $(OBJDIR)/, $(notdir $(CFILES:.c=.o)))

# Build Directory
BINDIR = $(PROJECT)/bin

# Add paths
VPATH = $(PROJECT) $(SRCDIR) $(COMDIR) $(OBJDIR) $(BINDIR)

# List of files for make_clean
GENERATED_BINS = $(BINDIR)/*.elf $(BINDIR)/*.bin $(BINDIR)/*.map $(BINDIR)/*.list $(BINDIR)/*.lss

#############################################################
# Specific Project Files
#############################################################

# App
$(PROJECT)_OBJS 	= $(filter-out %/$(BOOTLOADER).o, $(OBJS))
# Bootloader
$(BOOTLOADER)_OBJS 	= $(filter-out  %/$(PROJECT).o, $(OBJS))

# Linker scripts
$(PROJECT)_LDSCRIPT 	= $(PROJECT)/$(PROJECT).ld
$(BOOTLOADER)_LDSCRIPT 	= $(PROJECT)/$(BOOTLOADER).ld
LDSCRIPTS				= $($(PROJECT)_LDSCRIPT) $($(BOOTLOADER)_LDSCRIPT)


#############################################################
# Options & Flags
#############################################################

CSTD ?= -std=c99

ifeq ($(D),)
OPT = -O3
else
OPT = -Og -ggdb3
endif

TGT_CPPFLAGS += -MD
TGT_CPPFLAGS += -Wall -Wundef $(INCLUDES)
TGT_CPPFLAGS += $(INCLUDES) $(OPENCM3_DEFS)

TGT_CFLAGS += $(OPT) $(CSTD)
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

TGT_LDFLAGS += -L$(OPENCM3_DIR)/lib -nostartfiles
TGT_LDFLAGS += $(ARCH_FLAGS)
TGT_LDFLAGS += -specs=nano.specs
TGT_LDFLAGS += -Wl,--gc-sections
TGT_LDFLAGS += -Wl,--print-gc-sections

ifeq ($(V),99)

endif

# Be silent per default, but 'make V=1' will show all compiler calls.
# If you're insane, V=99 will print out all sorts of things.
ifeq ($(V),0)
Q		:= @
NULL	:= 2>/dev/null
endif

#############################################################
# Top builds routines
#############################################################

all: project bootloader

bootloader:	$(BINDIR)/$(BOOTLOADER).elf $(BINDIR)/$(BOOTLOADER).bin $(BINDIR)/$(BOOTLOADER).lss $(BINDIR)/$(BOOTLOADER).list
			$(SIZE) $(BINDIR)/$(BOOTLOADER).elf

project:	$(BINDIR)/$(PROJECT).elf $(BINDIR)/$(PROJECT).bin $(BINDIR)/$(PROJECT).lss $(BINDIR)/$(PROJECT).list
			$(SIZE) $(BINDIR)/$(PROJECT).elf

clean:
	rm -rf $(OBJDIR) $(GENERATED_BINS)

print-%:
	@echo $* = $($*)

.PHONY: all clean print

#############################################################
# File build rules
#############################################################

%.elf: $(OBJS) $(LDSCRIPTS) $(LIBDEPS)
	@printf "  LD\t$@\n"
	@echo $(*F)_LDSCRIPT
	$(Q)$(LD) -T$($(*F)_LDSCRIPT) $(TGT_LDFLAGS) $(LDFLAGS) -Wl,-Map=$*.map $($(*F)_OBJS) $(LDLIBS) -o $@

$(OBJDIR)/%.o: %.c
	@printf "  CC\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TGT_CFLAGS) $(CFLAGS) $(TGT_CPPFLAGS) $(CPPFLAGS) -o $@.S -E $<
	$(Q)$(CC) $(TGT_CFLAGS) $(CFLAGS) $(TGT_CPPFLAGS) $(CPPFLAGS) -o $@ -c $<

%.bin: %.elf
	@printf "  OBJCOPY\t$@\n"
	$(Q)$(OBJCOPY) -O binary  $< $@

%.lss: %.elf
	$(OBJDUMP) -h -S $< > $@

%.list: %.elf
	$(OBJDUMP) -S $< > $@

-include $(OBJS:.o=.d)
