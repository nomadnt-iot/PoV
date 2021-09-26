#include <uPoV.h>
#include <hardware.h>
#include <string.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <symbols.h>

void display(unsigned char *dots, const char *msg, unsigned char delayTime, unsigned char charBreak)
{
    for (unsigned int i = 0; i < strlen(msg); i++)
    {
        display_char(dots, msg[i], delayTime, charBreak);
    }
}

void display_char(unsigned char *dots, const char c, unsigned char delayTime, unsigned char charBreak)
{
    for (unsigned char i = 0; i < (sizeof(symbols) / sizeof(symbols[0])); i++)
    {
        if (c == pgm_read_byte(&symbols[i].code))
        {
            for (unsigned char j = 0; j < LEDS_COUNT; j++)
            {
                display_column(dots, pgm_read_byte(&symbols[i].value[j]));
                _delay_ms(delayTime);
            }
            display_column(dots, 0);
        }
    }

    _delay_ms(charBreak);
}

void display_column(unsigned char *dots, unsigned char column)
{
    for (unsigned char i = 0; i < LEDS_COUNT; i++)
    {
        (column & _BV(i)) ? (_sbi(PORTB, dots[i])) : (_cbi(PORTB, dots[i]));
        // for some reason this is not working but anyways we need to abstract
        // device. We need to determine the right port
        // uint8_t port = digitalPinToPort(dots[i]);
        // (column & _BV(i)) ? (_sbi(port, dots[i])) : (_cbi(port, dots[i]));
    }
}