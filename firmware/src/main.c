/**
 *  PoV is a very simple persistent of vision display that use ATTiny85 and 5 leds
 */
#include <util/delay.h>
#include <hardware.h>
#include <uPoV.h>

#define DELAY_TIME 2
#define CHAR_BREAK 5

// defining led array
unsigned char LED[LEDS_COUNT] = {PB0, PB1, PB2, PB3, PB4};

int main(void)
{
    // Set led from 1 to 5 as output
    // LEDS_DDR |= (_BV(PB0) | _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB4));

    for (unsigned char i = 0; i < LEDS_COUNT; i++)
    {
        _sbi(LEDS_DDR, LED[i]);
    }

    for (unsigned char i = 0; i < LEDS_COUNT; i++)
    {
        _sbi(LEDS_PORT, LED[i]);
        _delay_ms(250);
    }

    for (unsigned char i = LEDS_COUNT; i > 0; i--)
    {
        _cbi(LEDS_PORT, LED[i - 1]);
        _delay_ms(250);
    }

    while (1)
    {
        display(LED, "jacopo sallemi", DELAY_TIME, CHAR_BREAK);
    }
}