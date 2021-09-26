#include <uPoV.h>
#include <hardware.h>
#include <string.h>
#include <util/delay.h>
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
    for (unsigned char i = 0; i < (sizeof(symbols) / sizeof(struct symbol_t)); i++)
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
    // We know that we have only 5 leds available mapped from PB0 to PB4 of our ATTinyX5
    // and this also mean that we have a register (PORTB) of 5 bits that can contain a 
    // number between 0 and 31. So here the magic is happening... just update the register
    // with the current column value and we are fine with just one line of code
    // anyways this is valid only in the case ot all pins in the same register
    LEDS_PORT = column;

    // for (unsigned char i = 0; i < LEDS_COUNT; i++)
    // {
    //     (column & _BV(i)) ? (_sbi(PORTB, dots[i])) : (_cbi(PORTB, dots[i]));
    //     PORTB |= column;
    //     // for some reason this is not working but anyways we need to abstract
    //     // device. We need to determine the right port
    //     // uint8_t port = digitalPinToPort(dots[i]);
    //     // (column & _BV(i)) ? (_sbi(port, dots[i])) : (_cbi(port, dots[i]));
    // }
}