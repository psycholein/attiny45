#define F_CPU 8000000UL

#include 	<stdlib.h>
#include 	<avr/io.h>
#include 	<avr/interrupt.h>
#include 	<avr/pgmspace.h>

#include 	"i2cslave.h"
#define 	I2CADDRESS 0x34

void init(void) {
    // Disable interrupts
    cli();

    // TWI slave init
    i2c_init(I2CADDRESS);

    // Re-enable interrupts
    sei();

    int i;
    for (i = 0; i < buffer_size; i++) {
        i2c_buffer[i] = 0;
    }
}

int main(void) {


    // Set port 1 to output
    DDRB |= (1 << PB4);

    init();

    while (1) {
        if (i2c_buffer[0] != 0) {
            PORTB &= ~(1 << PB4);
	} else {
            PORTB |= (1 << PB4);
        }
    }
}
