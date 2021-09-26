#ifndef HARDWARE_H
#define HARDWARE_H

#include <avr/io.h>
#include <avr/pgmspace.h>

// #define F_CPU 1000000UL

#define LEDS_COUNT 5
#define LEDS_PORT PORTB
#define LEDS_DDR DDRB

#define PA 1
#define PB 2
#define PC 3
#define PD 4

#define _sbi(port, bit) (port) |= _BV(bit)  // set port bit
#define _cbi(port, bit) (port) &= ~_BV(bit) // clear port bit
#define _tbi(port, bit) (port) ^= _BV(bit)  // toggle port bit

#define digitalPinToPort(P) (pgm_read_byte(digital_pin_to_port_PGM + (P)))

#define setPin(i) _sbi(digitalPinToPort(i), i)
#define clearPin(i) _cbi(digitalPinToPort(i), i)
// #define setPin(i) _sbi(PORTB, i)
// #define clearPin(i) _cbi(PORTB, i)

extern const uint8_t PROGMEM digital_pin_to_port_PGM[];

#endif