#ifndef uPOV_H
#define uPOV_H

void display(unsigned char *dots, const char *msg, unsigned char delayTime, unsigned char charBreak);
void display_char(unsigned char *dots, const char c, unsigned char delayTime, unsigned char charBreak);
void display_column(unsigned char *dots, unsigned char column);

#endif