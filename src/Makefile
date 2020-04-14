# set and/or export this to the base directory of your toolchain
# TODO bfosenv.sh
MAKEFILE_PATH = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
ROMSIZE_KB = 64
BP_DEV?=/dev/ttyUSB0

ifeq ($(MAKEFILE_PATH),)
$(error Could not determine MAKEFILE_PATH)
endif
TC_PATH ?= $(MAKEFILE_PATH)../opt/uClinux/bfin-elf/

#LDFLAGS="-mcpu=bf514"
LDFLAGS="-mcpu=bf533"
# set target for bfin-ldr, see its help output for mapping of models
#LDRTARGET="BF518"
LDRTARGET="BF533"
#CFLAGS=-std=c99 -Wall
CFLAGS=-std=c99 -Wall -Wno-unused -Werror

SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))
TC_PATH := $(if $(TC_PATH), $(abspath $(TC_PATH)))
BIN_PREFIX := $(if $(TC_PATH),$(TC_PATH)/bin/)
$(if $(TC_PATH),$(info Using toolchain under $(abspath $(TC_PATH))))


all: image.ldr

clean:
	rm -f *.o
	rm -f image.elf
	rm -f *.ldr

flash: image.bin
	flashrom -p buspirate_spi:auxpin=low,dev=$(BP_DEV) -w $<

image.bin: image.ldr
	cat $< /dev/zero | dd bs=1k count=$(ROMSIZE_KB) of=$@

%.o: %.c
	$(BIN_PREFIX)bfin-elf-gcc $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

image.elf: $(OBJS)
	$(BIN_PREFIX)bfin-elf-gcc $(LDFLAGS) -o $@ $^

%.ldr: %.elf
	$(BIN_PREFIX)bfin-ldr -T $(LDRTARGET) -c $@ $<
	$(BIN_PREFIX)bfin-ldr -T $(LDRTARGET) -s $@

.PHONY: all clean flash
