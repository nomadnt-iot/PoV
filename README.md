# PoV

**PoV** is a very simple **P**ersistent **o**f **V**ision display based on Atmel ATTinyX5 chips family.
It is making use of all 5 pins available on ATTinyX5 chips family and it is written in pure AVR-C.

# How it's work

The ATTinyX5 has only 5 GPIO pins suitable to drive our display. The follow schema
will help you to better understand how leds are connected to each pin.

It is using only 16 bytes of RAM and 634 bytes of Flash memory

```sh
RAM:   [          ]   3.1% (used 16 bytes from 512 bytes)
Flash: [=         ]   7.7% (used 634 bytes from 8192 bytes)
```

## Hardware 

The [Hardware](hardware) folder contains my first eagle implementation but a new version based on KiKad it will coming soon.
Anyways you can use the current one as starting point to your PoV. 

- 1x ATTinyX5
- 5x leds green
- 1x decoupling capacitor
- 1x switch
- 1x battery holder for CR2032
- Stripboard
- Some soldering cable

The circuit is power by a CR2032 so this is the reason for the switch... to turn on and off the PoV as required. The decoupling
capacitor is always a good idea to have expecially when we are powering device through battery and is connected as closet as possible the ATTinyX5. And finally The leds are all connected from the bottom to the top to the ATTinyX5's pins PB0, PB1, PB2, PB3, PB4.

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

The ATTinyX5 has only `PORTB` and can handle only 5 GPIO so [symbols.h](include/symbols.h) is provided to handle only char 5x5 pixels. Feel free to change it in according to your requirements.