#include "defBF533.h"
#include <stdint.h>

// approximate busy delay
void delay_ms(int16_t ms) {
	while (ms--) {
		volatile uint16_t cnt = 0x1fff;
		while (cnt--);
	}
}

#define PF_DIR(mask) *((uint16_t *)FIO_DIR) = (mask)
#define PF_SET(mask) *((uint16_t *)FIO_FLAG_S) = (mask)
#define PF_CLR(mask) *((uint16_t *)FIO_FLAG_C) = (mask)
#define PF_TGL(mask) *((uint16_t *)FIO_FLAG_T) = (mask)

int main(void) {
	// init GPIOs
	uint16_t pins =  PF7 | PF8 | PF9 | PF10 | PF11 | PF12 | PF13 | PF14 | PF15; // LEDs
	PF_DIR(pins);
	PF_CLR(pins);
	// infinite loop
	while (1) {
	// toggle GPIOs
		for (uint32_t i=7; i<16; i++) {
			PF_TGL(1<<i);
			delay_ms(300);
		}
	}
	return 0;
}
