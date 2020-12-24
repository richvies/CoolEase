PROJECT 		= 	../build/$(P)

FILES_DIR		=	lib/

ifeq ($(P), sensor)
FILES 		   	+= 	sensor.c si7051.c tmp112.c
endif

ifeq ($(P), hub)
FILES 		   	+= 	hub.c sim.c
TGT_CFLAGS	   	+=	-D_HUB	
endif

FILES			+= 	aes.c battery.c board_defs.c memory.c printf.c reset.c rfm.c serial_printf.c testing.c timers.c

CFILES = $(FILES:%.c=$(FILES_DIR)/%.c)

# TODO - you will need to edit these two lines!
DEVICE 		= 	stm32l051c8t6

# You shouldn't have to edit anything below here.
INCLUDES 	+= 	-I../coolease/include
OPENCM3_DIR  =	../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk