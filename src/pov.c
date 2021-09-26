/**
 *  PoV is a very simple persistent of vision display that use ATTiny85 and 5 leds
 */
#include <pov.h>

int main(void)
{
    // Here many ways how to assign pin a outout 
    DDRB = 0x1F; // DDRB = 32; // DDRB = _BV(LEDS_COUNT) - 1;
    // DDRB |= (_BV(PB0) | _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB4));

    for (unsigned char i = 0; i < LEDS_COUNT; i++)
    {
        _sbi(PORTB, i);
        _delay_ms(250);
    }

    for (unsigned char i = LEDS_COUNT; i > 0; i--)
    {
        _cbi(PORTB, (i - 1));
        _delay_ms(250);
    }

    while (1)
    {
        display("jacopo sallemi", 2, 5);
    }
}

void display(const char *msg, unsigned char delayTime, unsigned char charBreak)
{
    for (unsigned int i = 0; i < strlen(msg); i++)
    {
        display_char(msg[i], delayTime, charBreak);
    }
}

void display_char(const char c, unsigned char delayTime, unsigned char charBreak)
{
    for (unsigned char i = 0; i < (sizeof(symbols) / sizeof(struct symbol_t)); i++)
    {
        if (c == pgm_read_byte(&symbols[i].code))
        {
            for (unsigned char j = 0; j < COLS_COUNT; j++)
            {
                // We know that we have only 5 leds available mapped from PB0 to PB4 of our ATTinyX5
                // and this also mean that we have a register (PORTB) of 5 bits that can contain a 
                // number between 0 and 31. So here the magic is happening... just update the register
                // with the current column value and we are fine with just one line of code
                PORTB = pgm_read_byte(&symbols[i].value[j]);
                _delay_ms(delayTime);
            }

            // Turn off all the output
            PORTB = 0;
        }
    }

    _delay_ms(charBreak);
}