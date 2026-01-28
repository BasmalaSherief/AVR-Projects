/*
 * PWM_driver.h
 *
 *  Created on: Oct 8, 2022
 *      Author: basmala sherief
 */

#ifndef PWM_DRIVER_H_
#define PWM_DRIVER_H_
#include "std_types.h"

#define TIMER0_OCO_PORT_ID    1
#define TIMER0_OCO_PIN_ID     3

/* functions prototypes */
/*
The function responsible for trigger the Timer0 with the PWM Mode.
Setup the PWM mode with Non-Inverting.
Setup the prescaler with F_CPU/8.
Setup the compare value based on the required input duty cycle
Setup the direction for OC0 as output pin through the GPIO driver.
The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_DRIVER_H_ */
