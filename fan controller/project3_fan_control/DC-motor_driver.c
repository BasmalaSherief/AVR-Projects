/*
 * DC-motor_driver.c
 *
 *  Created on: Oct 8, 2022
 *      Author: basmala sherief
 */
#include "dc-motor_driver.h"
#include "gpio_driver.h"
#include "pwm_driver.h"
#include "common_macros.h"
/* functions prototypes */
/*
The Function responsible for setup the direction for the two motor pins through the GPIO driver.
Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_init(void){
	/* Set direction for the motor pins */
	GPIO_setupPinDirection(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,PIN_OUTPUT);
	/* stop the motor at first */
	GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
}

/*
The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	if(state==STOP){
		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
		PWM_Timer0_Start(speed);
	}
	else if(state==CW){
		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_HIGH);
		PWM_Timer0_Start(speed);
	}
	else if(state==ACW){
		GPIO_writePin(DC_MOTOR_PORT1_ID,DC_MOTOR_PIN1_ID,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT2_ID,DC_MOTOR_PIN2_ID,LOGIC_LOW);
		PWM_Timer0_Start(speed);
	}
	else
	{
		/*Do nothing*/
	}
}
