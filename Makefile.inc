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
.SECONDARY: $(OBJS) # So that make does not think they are intermediate files and delete them

# Build Directory
BINDIR = $(PROJECT)/bin

# Add paths
VPATH = $(PROJECT) $(SRCDIR) $(COMDIR) $(OBJDIR) $(BINDIR)

# List of files for make_clean
GENERATED_BINS = $(BINDIR)/*.elf $(BINDIR)/*.hex $(BINDIR)/*.bin $(BINDIR)/*.map $(BINDIR)/*.list $(BINDIR)/*.lss

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
# Conditional Flags
#############################################################

# Hub or sensor
ifeq ($(PROJECT), hub)
TGT_CFLAGS	   	+=	-D_HUB
endif

# Release or debug version
ifeq ($(R), 1)
OPT = -Os -s 
else
OPT = -Og -ggdb3
TGT_CFLAGS += -DDEBUG
endif

# Be silent per default, but 'make V=1' will show all compiler calls.
# If you're insane, V=99 will print out all sorts of things.
V ?= 0
ifeq ($(V),0)
Q		:= @
NULL	:= 2>/dev/null
endif

# Print sections if verbose
ifeq ($(V),99)
TGT_LDFLAGS += -Wl,--print-gc-sections
endif

#############################################################
# General Options & Flags
#############################################################

CSTD ?= -std=c99

TGT_CPPFLAGS += -MD
TGT_CPPFLAGS += -Wall -Wundef $(INCLUDES)
TGT_CPPFLAGS += $(INCLUDES) $(OPENCM3_DEFS)

TGT_CFLAGS += $(OPT) $(CSTD)
TGT_CFLAGS += $(ARCH_FLAGS)
TGT_CFLAGS += -fno-common
TGT_CFLAGS += -ffunction-sections -fdata-sections
TGT_CFLAGS += -Wextra -Wshadow -Wno-unused-variable -Wimplicit-function-declaration
TGT_CFLAGS += -Wredundant-decls -Wstrict-prototypes -Wmissing-prototypes

TGT_ASFLAGS += $(OPT) $(ARCH_FLAGS)

TGT_LDFLAGS += -L$(OPENCM3_DIR)/lib -nostartfiles
TGT_LDFLAGS += $(ARCH_FLAGS)
TGT_LDFLAGS += -specs=nano.specs
TGT_LDFLAGS += -Wl,--gc-sections
TGT_LDFLAGS += -Wl,--nmagic

#############################################################
# Top builds routines
#############################################################

all: project bootloader

bootloader:	$(BINDIR)/$(BOOTLOADER).elf $(BINDIR)/$(BOOTLOADER).hex $(BINDIR)/$(BOOTLOADER).bin $(BINDIR)/$(BOOTLOADER).lss $(BINDIR)/$(BOOTLOADER).list
			$(SIZE) $(BINDIR)/$(BOOTLOADER).elf

project:	$(BINDIR)/$(PROJECT).elf $(BINDIR)/$(PROJECT).hex $(BINDIR)/$(PROJECT).bin $(BINDIR)/$(PROJECT).lss $(BINDIR)/$(PROJECT).list
			$(SIZE) $(BINDIR)/$(PROJECT).elf

clean:
	rm -rf $(OBJDIR) $(GENERATED_BINS)

print-%:
	@echo $* = $($*)

.PHONY: all bootloader project clean print-

#############################################################
# File build rules
#############################################################

%.elf: $(OBJS) $(LDSCRIPTS) $(LIBDEPS)
	@printf "  LD\t$@\n"
	$(Q)$(LD) -T$($(*F)_LDSCRIPT) $(TGT_LDFLAGS) $(LDFLAGS) -Wl,-Map=$*.map $($(*F)_OBJS) $(LDLIBS) -o $@

$(OBJDIR)/%.o: %.c
	@printf "  CC\t$<\n"
	@mkdir -p $(dir $@)
	$(Q)$(CC) $(TGT_CFLAGS) $(CFLAGS) $(TGT_CPPFLAGS) $(CPPFLAGS) -o $@.S -E $<
	$(Q)$(CC) $(TGT_CFLAGS) $(CFLAGS) $(TGT_CPPFLAGS) $(CPPFLAGS) -o $@ -c $<

%.hex: %.elf
	@printf "  OBJCOPY\t$@\n"
	$(Q)$(OBJCOPY) -O ihex  $< $@

%.bin: %.elf
	$(Q)$(OBJCOPY) -O binary  $< $@

%.lss: %.elf
	$(OBJDUMP) -h -S $< > $@

%.list: %.elf
	$(OBJDUMP) -S $< > $@

test.elf: $(TESTOBJS)
	@printf "  LD\t$@\n"
	$(Q)$(LD) -Thub/hub.ld $(TGT_LDFLAGS) $(LDFLAGS) -Wl,-Map=$*.map $(TESTOBJS) $(LDLIBS) -o $@
	$(OBJDUMP) -x test.elf
	$(SIZE) test.elf
	rm -rf test.elf

-include $(OBJS:.o=.d)
