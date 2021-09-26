#include <hardware.h>

#if defined(__AVR_ATtiny85__)
const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
    PB,
    PB,
    PB,
    PB,
    PB};
#elif defined(__AVR_ATmega328P__)
const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
    PD, /* 0 */
    PD,
    PD,
    PD,
    PD,
    PD,
    PD,
    PD,
    PB, /* 8 */
    PB,
    PB,
    PB,
    PB,
    PB,
    PC, /* 14 */
    PC,
    PC,
    PC,
    PC,
    PC};
#endif
