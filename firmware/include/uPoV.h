#ifndef uPOV_H
#define uPOV_H

#define DELAY_TIME 2
#define CHAR_BREAK 5

void display(unsigned char *dots, const char *msg);
void display_char(unsigned char *dots, const char c);
void display_column(unsigned char *dots, unsigned char column);

#endif