#ifndef _uPoV_H_
#define _uPoV_H_

#include <Arduino.h>
#include <Symbols.h>

class uPoV{
	public:
		/**
		 * class constructor
		 */
		uPoV(uint8_t *leds, uint8_t size, uint8_t delayTime = 2, uint8_t charBreak = 5);

		/**
		 * display message on pov led bar
		 */
    	void display(const char *msg);

		/**
		 * execute led test
		 */
		void test();
	private:

		/**
		 * delay time between subchar elements
		 */
    	uint8_t _delayTime;

		/**
		 * delay time between two chars
		 */
    	uint8_t _charBreak;

		/**
		 * leds array
		 */
    	uint8_t *_leds;

		/**
		 * size of leds array
		 */
    	uint8_t _size;

		/**
		 * display single char
		 */
    	void __char(char c);

		/**
		 * display single line of a char
		 */
    	void __line(uint8_t line);
};

#endif
