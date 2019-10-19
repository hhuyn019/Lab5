/ // Sets B to bbbbbb01
					// (clear rightmost 2 bits, then set to 01*	Author: hhuyn019
 *  Partner(s) Name: Badr Asi
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTB = 0x00;
	unsigned char ignit = 0x00;
	unsigned char gasLev = 0x00;
    /* Insert your solution below */
    while (1) {
	ignit = ~PINA & 0x00;
	gasLev = ~PINA & 0x00;
	switch(gasLev) {
		case 0:
			PORTC = 0x40;
			break;
		case 1:
		case 2:
			PORTC = 0x60;
			break;
		case 3:
		case 4:
			PORTC = 0x70;
			break;
		case 5:
		case 6:
			PORTC = 0x38;
			break;
		case 7:
		case 8:
		case 9:
			PORTC = 0x3C;
			break;
		case 10:
		case 11:
		case 12:
			PORTC = 0x3E;
			break;
		case 13:
		case 14:
		case 15:
			PORTC = 0x3F;
			break;
		default:
			PORTC = 0x00;
			break;
	}

	if (ignit == 0x30) {
		PORTC = PORTC | 0x80;
	}
    }

	return 1;
}
