TC_PATH ?= ../opt/uClinux/bfin-elf/bin/
CROSS_COMPILE = $(pathjoin $(abspath $(TC_PATH)), "bfin-elf-")

LDFLAGS="-mcpu=bf514"
# set target for bfin-ldr, see its help output for mapping of models
LDRTARGET="BF518"

SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))


all: image.ldr

clean:
	rm -f *.o
	rm -f image.elf
	rm -f *.ldr

%.o: %.c
	$(CROSS_COMPILE)gcc $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

image.elf: $(OBJS)
	$(CROSS_COMPILE)gcc $(LDFLAGS) -o $@ $^

%.ldr: %.elf
	$(TC_PATH)/bfin-ldr -T $(LDRTARGET) -c $@ $<

.PHONY: all clean
