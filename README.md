- [What is a PoV display](#what-is-a-pov-display)
- [Introduction](#introduction)
- [How it's work](#how-its-work)
  - [Output pins](#output-pins)
  - [Display text](#display-text)
- [Hardware](#hardware)
  - [Components used](#components-used)
- [Useful links](#useful-links)

# What is a PoV display

[Here](https://en.wikipedia.org/wiki/Persistence_of_vision) the definition of Persistence of Vision Display from wikipedia.

*The term "persistence of vision display" or "POV display" has been used for LED display devices that compose images by displaying one spatial portion at a time in rapid succession, (for example, one column of pixels every few milliseconds). A two-dimensional POV display is often accomplished by means of rapidly moving a single row of LEDs along a linear or circular path. The effect is that the image is perceived as a whole by the viewer as long as the entire path is completed during the visual persistence time of the human eye. A further effect is often to give the illusion of the image floating in mid-air.*

A common example of this can be seen in the use of bicycle wheel lights that produce patterns.

# Introduction

**PoV** is a very simple **P**ersistent **o**f **V**ision display based on Atmel ATTinyX5 chips family.
It is making use of all 5 pins available on ATTinyX5 chips family and it is written in pure AVR-C.

# How it's work

The ATTinyX5 has only 5 GPIO pins suitable to drive our display. The [Schematic](hardware/schematic.pdf) will help you to better understand how leds are connected to each pin.

It is using only 16 bytes of RAM and 634 bytes of Flash memory

```sh
RAM:   [          ]   3.1% (used 16 bytes from 512 bytes)
Flash: [=         ]   7.7% (used 634 bytes from 8192 bytes)
```

## Output pins

First we have to set all the 5 pins on the ATTinyX5 as output.

```c
#include <pov.h>

int main(void)
{
    DDRB = 0x1F; // 0x1F is equals to 31 that is equals to 1 << 5
    ...
}
```

## Display text

In order to display text we need to call the `display` method in a loop like the following

```c
#include <pov.h>

int main(void)
{
    DDRB = 0x1F; // 0x1F is equals to 31 that is equals to 1 << 5

    while (1)
    {
        display("jacopo sallemi", 2, 5);
    }
}
```

Than the `display` function is looping through all the chars in the string and call the `display_char` method that is just getting the encoded corrisponding `value` related to the processed char and than configure the `PORTB` in accoding to the value.

```c
void display_char(const char c, unsigned char delayTime, unsigned char charBreak)
{
    for (unsigned char i = 0; i < (sizeof(symbols) / sizeof(struct symbol_t)); i++)
    {
        if (c == pgm_read_byte(&symbols[i].code))
        {
            for (unsigned char j = 0; j < COLS_COUNT; j++)
            {
                // Configure PORTB with the current encoded value
                PORTB = pgm_read_byte(&symbols[i].value[j]);
                _delay_ms(delayTime);
            }

            // Turn off all the output
            PORTB = 0;
        }
    }

    _delay_ms(charBreak);
}
```

# Hardware 

The [Hardware](hardware) folder contains my first eagle implementation and a new version based on KiKad.
Anyways you can use both of them as starting point to your PoV project. 

- [Schematic](hardware/schematic.pdf)
- [3D model](hardware/PoV.png)

## Components used

- 1x ATTinyX5
- 5x leds green
- 1x 100 nF decoupling capacitor
- 1x switch
- 1x R2032
- 1x battery holder for CR2032
- Stripboard
- Some soldering cable

The circuit is power by a CR2032 so this is the reason for the switch... to turn on and off the PoV as required.  
The decoupling capacitor is always a good idea to have expecially when we are powering devices through battery and is connected as closet as possible the ATTinyX5.  
And finally The leds are all connected from the bottom to the top to the ATTinyX5's pins PB0, PB1, PB2, PB3, PB4.

```
LEDS CONNECTION

            PB4 [] LED5

            PB3 [] LED4

            PB2 [] LED3

            PB1 [] LED2

            PB0 [] LED1

              +-\/-+
        PB5  1|    |8   VCC
(LED4)  PB3  2|    |7   PB2  (LED3)
(LED5)  PB4  3|    |6   PB1  (LED2)
        GND  4|    |5   PB0  (LED1)
              +----+

```

The ATTinyX5 has only `PORTB` and can handle only 5 GPIO so [symbols.h](include/symbols.h) is provided to handle only char 5x5 pixels.  
Feel free to change it in according to your requirements.

# Useful links

- [Programming AVR Microcontrollers in C - O'Reilly Webcast](https://youtu.be/ERY7d7W-6nA)
- [Font 5x5 pixel resource 1](https://www.dafont.com/5x5.font)
- [Font 5x5 pixel resource 2](https://www.1001fonts.com/5x5-font.html)
- [ATTinyX5 Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-2586-AVR-8-bit-Microcontroller-ATtiny25-ATtiny45-ATtiny85_Datasheet.pdf)