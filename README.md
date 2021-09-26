# PoV

**PoV** is a very simple **P**ersistent **o**f **V**ision display based on Atmel ATTinyX5 chips family.
It is making use of all 5 pins available on ATTinyX5 chips family and it is written in pure AVR-C.

# How it's work

The ATTinyX5 has only 5 GPIO pins suitable to drive our display. The follow schema
will help you to better understand how leds are connected to each pin.

```
ATTINYX5 LED CONNECTION

              +-\/-+
        PB5  1|    |8   VCC
(LED4)  PB3  2|    |7   PB2  (LED3)
(LED5)  PB4  3|    |6   PB1  (LED2)
        GND  4|    |5   PB0  (LED1)
              +----+
```

## Hardware 

The [Hardware](hardware) folder contains my first eagle implementation but a new version based on KiKad it will coming soon.
Anyways you can use the current one as starting point to your PoV. 