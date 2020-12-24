PROJECT 		= 	../build/$(P)

FILES_DIR		=	lib/
FILES			= 	board_defs.c battery.c cc1101.c encryption.c printf.c reset.c rf_scan.c serial_printf.c
FILES			+= 	si7051.c sim800.c testing.c timers.c tmp112.c

ifeq ($(P), sensor)
FILES 		   	+= 	sensor.c
endif

ifeq ($(P), hub)
FILES 		   	+= 	hub.c
TGT_CFLAGS	   	+=	-D_HUB	
endif


CFILES = $(FILES:%.c=$(FILES_DIR)/%.c)

# TODO - you will need to edit these two lines!
DEVICE 		= 	stm32l021d4p6

# You shouldn't have to edit anything below here.
INCLUDES 	+= 	-I../coolease/include
OPENCM3_DIR  =	../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk