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

enum SM_States {init, add, sub, wait, reset} SM_State;
unsigned char tmpC = 0x00;

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTB = 0x00;
	SM_State = init;
    /* Insert your solution below */
    while (1) {
	Tick();
    }
	return 1;
}

void Tick() {
	switch(SM_State) {
		case init:
			SM_State = init;
			break;
		case add:
		case sub:
		case reset:
		case wait:
			if(~PINA == 0x01) {
				SM_State = add;
				break;
			} else if(~PINA == 0x02) {
				SM_State = sub;
				break;
			} else if(~PINA == 0x03) {
				SM_State = reset;
				break;
			} else {
				SM_State = wait;
				break;
			}
	}

	switch(SM_State) {
		case init:
			tmpC = 0x00;
			SM_State = wait;
			break;
		case wait:
			tmpC = tmpC;
			SM_State = wait;
			break;
		case add:
			if(tmpC >= 9) {
				tmpC = 0x09;
				SM_State = wait;
				break;
			} else {
				tmpC = tmpC + 0x01;
				SM_State = wait;
				break;
			}
		case sub:
			if(tmpC <= 0) {
				tmpC = 0x00;
				SM_State = wait;
				break;
			} else {
				tmpC = tmpC - 0x01;
				SM_State = wait;
				break;
			}
		case reset:
			tmpC = 0x00;
			SM_State = wait;
	}
	PORTC = tmpC;
}
