/*
 * DC-motor_driver.h
 *
 *  Created on: Oct 8, 2022
 *      Author: basmala sherief
 */

#ifndef DC_MOTOR_DRIVER_H_
#define DC_MOTOR_DRIVER_H_
#include "std_types.h"

/* Definition */
/* The ports and the pins of the dc motor */
#define DC_MOTOR_PORT1_ID PORTB_ID
#define DC_MOTOR_PORT2_ID PORTB_ID
#define DC_MOTOR_PIN1_ID PIN0_ID
#define DC_MOTOR_PIN2_ID PIN1_ID

/* enums */
typedef enum{ /* to select the state of the motor*/
	STOP,CW,ACW
}DcMotor_State;

/* functions prototypes */
/*
The Function responsible for setup the direction for the two motor pins through the GPIO driver.
Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_init(void);

/*
The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_DRIVER_H_ */
