PROJECT	= app
OBJDIR  = obj

GCCPATH = ~/gcc-arm-none-eabi-8-2018-q4-major/bin
CC      = $(GCCPATH)/arm-none-eabi-gcc
OBJCOPY = $(GCCPATH)/arm-none-eabi-objcopy
SIZE    = $(GCCPATH)/arm-none-eabi-size

CFLAGS += -std=gnu99
CFLAGS += -Os
CFLAGS += -Qn
CFLAGS += -static
CFLAGS += -fno-builtin

LDFLAGS += -nostartfiles
LDFLAGS += -nostdlib
LDFLAGS += -Wl,--gc-sections,--build-id=none
LDFLAGS += -Tlinker.ld



all: $(OBJDIR)/$(PROJECT)

$(OBJDIR)/$(PROJECT): _start.c
	$(CC) -mthumb -mcpu=cortex-m0 -mthumb-interwork -I. $(CFLAGS) -c         $<                   -o $(OBJDIR)/$(<:.c=.o) 
	$(CC) -mthumb -mcpu=cortex-m0 -mthumb-interwork -I. $(CFLAGS) $(LDFLAGS) $(OBJDIR)/$(<:.c=.o) -o $@
	${OBJCOPY} -S $@ -g -O binary $@.bin
	$(SIZE) -A $@

clean:
	rm -f -r $(OBJDIR) | exit 0

-include $(shell mkdir $(OBJDIR) 2>/dev/null)
