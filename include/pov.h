#ifndef POV_H
#define POV_H

#include <string.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "symbols.h"

#define LEDS_COUNT 5        // the number of leds
#define COLS_COUNT 5        // the number of columns (5 leds by 5 columns mean 5x5 char)
#define CHAR_DISPLAY_TIME 2 // how long the char will be shown
#define CHAR_BREAK_TIME 5   // the time delay between 2 chars

#define _sbi(port, bit) (port) |= _BV(bit)  // set port bit
#define _cbi(port, bit) (port) &= ~_BV(bit) // clear port bit
#define _tbi(port, bit) (port) ^= _BV(bit)  // toggle port bit

void display(const char *msg, unsigned char delayTime, unsigned char charBreak);
void display_char(const char c, unsigned char delayTime, unsigned char charBreak);

#endif