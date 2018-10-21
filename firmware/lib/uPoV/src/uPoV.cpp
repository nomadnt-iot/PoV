#include <uPoV.h>

uPoV::uPoV(uint8_t *leds, uint8_t size, uint8_t delayTime, uint8_t charBreak){
    _delayTime = delayTime;
    _charBreak = charBreak;
    _leds = leds;
    _size = size;

    for(uint8_t i = 0; i < _size; i++){
        pinMode(_leds[i], OUTPUT);
    }
}

void uPoV::display(const char *msg){
    for(unsigned int i = 0; i <= strlen(msg); i++){
        __char(msg[i]);
    }
}

void uPoV::test(){
    for(uint8_t i = 0; i < _size; i++){
        digitalWrite(_leds[i], HIGH);
        delay(250);
    }

    for(uint8_t i = 0; i < _size; i++){
        digitalWrite(_leds[(_size - 1) - i], LOW);
        delay(250);
    }
}

void uPoV::__char(char c){
    for(uint8_t i = 0; i < (sizeof(symbols) / sizeof(symbols[0])); i++){
        if(c == pgm_read_byte(&symbols[i].code)){
            for(uint8_t j = 0; j < _size; j++){
                __line(pgm_read_byte(&symbols[i].value[j]));
                delay(_delayTime);
            }
            __line(0);
        }
    }

    delay(_charBreak);
}

void uPoV::__line(uint8_t line){
    if(line >= 16) { digitalWrite(_leds[0], HIGH); line -= 16; } else { digitalWrite(_leds[0], LOW); }
    if(line >=  8) { digitalWrite(_leds[1], HIGH); line -=  8; } else { digitalWrite(_leds[1], LOW); }
    if(line >=  4) { digitalWrite(_leds[2], HIGH); line -=  4; } else { digitalWrite(_leds[2], LOW); }
    if(line >=  2) { digitalWrite(_leds[3], HIGH); line -=  2; } else { digitalWrite(_leds[3], LOW); }
    if(line >=  1) { digitalWrite(_leds[4], HIGH); line -=  1; } else { digitalWrite(_leds[4], LOW); }
}
