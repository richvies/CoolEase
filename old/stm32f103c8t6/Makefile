sensor:
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/battery.o -c coolease/battery.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/cc1101.o -c coolease/cc1101.c 
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/encryption.o -c coolease/encryption.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/led.o -c coolease/led.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/printf.o -c coolease/printf.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/reset.o -c coolease/reset.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/rf_scan.o -c coolease/rf_scan.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/sensor.o -c coolease/sensor.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/serial_printf.o -c coolease/serial_printf.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/si4432.o -c coolease/si4432.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/si7051.o -c coolease/si7051.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/sim800.o -c coolease/sim800.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/stm_temp.o -c coolease/stm_temp.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/timers.o -c coolease/timers.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/tmp112.o -c coolease/tmp112.c
	$(CC) $(TGT_CFLAGS) $(TGT_CPPFLAGS) -o build/aes.o -c crypto/tinyAes/aes.c
	$(CC) $(TGT_LDFLAGS) build/battery.o build/cc1101.o build/encryption.o build/led.o build/printf.o build/reset.o build/rf_scan.o build/sensor.o build/serial_printf.o build/si4432.o build/si7051.o build/sim800.o build/stm_temp.o build/timers.o build/tmp112.o build/aes.o $(LDLIBS) -o build/sensor.elf
	$(SIZE) build/sensor.elf
	$(OBJCOPY) -Obinary build/sensor.elf build/sensor.bin
	arm-none-eabi-objdump -D build/sensor.elf > build/sensor.lst

hub:

CC			:= $(CURDIR)/util/gcc-arm/bin/arm-none-eabi-gcc
OBJCOPY		:= $(CURDIR)/util/gcc-arm/bin/arm-none-eabi-objcopy
SIZE		:= $(CURDIR)/util/gcc-arm/bin/arm-none-eabi-size
OBJDUMP		:= $(CURDIR)/util/gcc-arm/bin/arm-none-eabi-objdump
GDB			:= $(CURDIR)/util/gcc-arm/bin/arm-none-eabi-gdb

LDSCRIPT	:= $(CURDIR)/util/ld/stm32f103c8t6.ld

OPENCM3_DIR := $(CURDIR)/libopencm3
LIBNAME		= opencm3_stm32f1
DEFS		+= -DSTM32F1

CRPYTO_DIR	:= $(CURDIR)/crypto
CE_DIR		:= $(CURDIR)

FP_FLAGS	?= -msoft-float
ARCH_FLAGS	= -mthumb -mcpu=cortex-m3 $(FP_FLAGS) -mfix-cortex-m3-ldrd
ASFLAGS		= -mthumb -mcpu=cortex-m3 --verbose


OPT			:= -Os -g
CSTD		?= -std=c99
TGT_CFLAGS	+= $(OPT) $(CSTD)
TGT_CFLAGS	+= $(ARCH_FLAGS)
TGT_CFLAGS	+= -Wextra -Wshadow -Wimplicit-function-declaration
TGT_CFLAGS	+= -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes
TGT_CFLAGS	+= -fno-common -ffunction-sections -fdata-sections
TGT_CFLAGS	+= -I$(OPENCM3_DIR)/include
TGT_CFLAGS	+= -I$(CRPYTO_DIR)
TGT_CFLAGS	+= -I$(CE_DIR)

TGT_CPPFLAGS	+= -MD
TGT_CPPFLAGS	+= -Wall -Wundef
TGT_CPPFLAGS	+= $(DEFS)
TGT_CPPFLAGS	+= -I$(OPENCM3_DIR)/include

TGT_LDFLAGS	+= --static -nostartfiles
TGT_LDFLAGS	+= -T$(LDSCRIPT)
TGT_LDFLAGS	+= $(ARCH_FLAGS)
TGT_LDFLAGS	+= -Wl,-Map=build/sensor.map
TGT_LDFLAGS	+= -Wl,--gc-sections

LDLIBS		+= -specs=nosys.specs
LDLIBS		+= -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group
LDLIBS		+= -L$(OPENCM3_DIR)/lib -lopencm3_stm32f1

clean:
	@#printf "  CLEAN\n"
	rm -f build/*.o build/*.d generated.* build/*.hex build/*.srec build/*.lst build/*.map

clobber: clean
	rm -f build/*.elf build/*.bin

flashsensor: sensor
		$(CURDIR)/util/upload/stm32flash/stm32flash -w build/sensor.bin -v -g 0x0 /dev/cu.usbserial-A50285BI

.PHONY: images clean elf bin hex srec list all

-include $(OBJS:.o=.d)

# End
