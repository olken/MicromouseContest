/*
 * test_I2C.c
 *
 * Created: 12/03/2016 16:44:14
 *  Author: jolan barbancon
 */ 
#include "Global.h"

#ifdef TEST_MOTEUR

#ifndef F_CPU
#define F_CPU 1000000UL // 1 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "Moteur.h"

//Gen PWM of 25% on A and 75% on B

int main(void)
{
	SET(DDRC,PORTC0); //Makes PORTC0 as Output
	
	PWM_Init();
	PWM_SetDutyCycleA(0x03FF);
	PWM_SetDutyCycleB(0x0BFF);
	
	while(1) //infinite loop
	{
		TOG(PORTC,PORTC0);//Turns ON PORTC0 LEDs
		_delay_ms(1000); //1 second delay
	}
}

#endif