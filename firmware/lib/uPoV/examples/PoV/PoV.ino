/**
 *  PoV is a very simple persistent of vision display that use ATTiny85
 *  and 5 leds
 **/
#include <uPoV.h>

// led matrix
uint8_t LED[] = {4, 3, 2, 1, 0};
uPoV pov = uPoV(LED, 5);

void setup(){
    // perform leds test
    pov.test();
}

void loop(){
    // display message
    pov.display("jacopo sallemi");
}
