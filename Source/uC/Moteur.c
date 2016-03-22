#ifndef F_CPU
#define F_CPU 1000000UL // 1 MHz clock speed
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Global.h"
#include "Moteur.h"

/*
Recap of register : I indicate the timer used (0-2)
	OCRIX -> Duty_cycle Value X mean A or B to select the PWM
	TCCRIA -> PWM Mode (Invert, Non invert, Fast or Phase corrected)
	TCCRIB -> PWM prescaler clock
	
	Here we used 16-Bit Timer1 with output PWM on pin OC1A : (15) and OC1B (16)
*/

void PWM_Init()
{
	//Set the PWM Pin as Output
	SET(DDRB,PORTB1);
	SET(DDRB,PORTB2);
	
	//Init duty_ycle to 0
	OCR1A = 0;
	OCR1B = 0;
	
	//Set TOP Value
	ICR1 = 0x0FFF; //-> PWM Frequency = clock/(2*ICR1) = clock/131070
	
	
	//Set the mode of operation
	//COM1X1 -> Non Inverted Mode
	//WGM13 set Phase and Frequency corrected mode, with top value on 16bit register ICR1 (define PWM frequency)
	//CS10 No clock prescaler
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1);
	TCCR1B |= (1 << WGM13) | (1 << CS10);
	
}

void PWM_SetDutyCycleA(uint16_t duty_cycle)
{
	OCR1A = duty_cycle;
}

void PWM_SetDutyCycleB(uint16_t duty_cycle)
{
	OCR1B = duty_cycle;
}