/**
 *  PoV is a very simple persistent of vision display that use ATTiny85 and 5 leds
 */
#include <util/delay.h>
#include <hardware.h>
#include <uPoV.h>

// defining led array
unsigned char LED[LEDS_COUNT] = {PB4, PB3, PB2, PB1, PB0};

int main(void)
{
    // Heremany ways how to assign pin a outout 
    // LEDS_DDR |= (_BV(PB0) | _BV(PB1) | _BV(PB2) | _BV(PB3) | _BV(PB4));
    // LEDS_DDR = 0x1F;
    // LEDS_DDR = 32;
    // LEDS_DDR = (1 << LEDS_COUNT) - 1;

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
        display(LED, "jacopo sallemi", 2, 5);
    }
}