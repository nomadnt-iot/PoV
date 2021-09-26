#ifndef HARDWARE_H
#define HARDWARE_H

#include <avr/io.h>
#include <avr/pgmspace.h>

#define LEDS_COUNT 5
#define LEDS_PORT PORTB
#define LEDS_DDR DDRB

#define _sbi(port, bit) (port) |= _BV(bit)  // set port bit
#define _cbi(port, bit) (port) &= ~_BV(bit) // clear port bit
#define _tbi(port, bit) (port) ^= _BV(bit)  // toggle port bit

#endif