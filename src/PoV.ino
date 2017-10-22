#include <uPoV.h>

// led matrix
uint8_t LED[] = {4, 3, 2, 1, 0};

uPoV pov = uPoV(LED, 5, 2, 5);

void setup(){
  for(uint8_t i = 0; i < 5; i++){
    digitalWrite(LED[i], HIGH);
    delay(250);
  }

  for(uint8_t i = 0; i < 5; i++){
    digitalWrite(LED[4 - i], LOW);
    delay(250);
  }
}

void loop(){
  pov.display("jacopo sallemi");
}
