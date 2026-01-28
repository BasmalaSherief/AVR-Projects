/*
 * PWM_driver.c
 *
 *  Created on: Oct 8, 2022
 *      Author: basmala sherief
 */
#include "pwm_driver.h"
#include "gpio_driver.h"
#include "common_macros.h"
#include <avr/io.h>

/* functions definitions */
/*
The function responsible for trigger the Timer0 with the PWM Mode.
Setup the PWM mode with Non-Inverting.
Setup the prescaler with F_CPU/8.
Setup the compare value based on the required input duty cycle
Setup the direction for OC0 as output pin through the GPIO driver.
The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 */
void PWM_Timer0_Start(uint8 duty_cycle){
	GPIO_setupPinDirection(TIMER0_OCO_PORT_ID,TIMER0_OCO_PIN_ID,PIN_OUTPUT);
	TCNT0 = 0; //Set Timer Initial value
	uint8 speed = (((float)duty_cycle/100)*255);
	OCR0  = speed; // Set Compare Value
	TCCR0 = (1<<WGM00) |(1<<WGM01) |(1<<COM01) |(1<<CS01);
}
