CROSS_COMPILE=../opt/uClinux/bfin-elf/bin/bfin-elf-

LDFLAGS="-mcpu=bf514"

SRCS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(SRCS))

all: image.elf

clean:
	rm -f *.o
	rm -f image.elf

%.o: %.c
	$(CROSS_COMPILE)gcc $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

image.elf: $(OBJS)
	$(CROSS_COMPILE)gcc $(LDFLAGS) -o $@ $^

.PHONY: all clean
