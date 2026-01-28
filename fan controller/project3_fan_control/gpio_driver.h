/*
 * gpio_driver.h
 *
 *  Created on: Oct 6, 2022
 *      Author: Basmala Sherief
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_
#include "std_types.h"

/* Definition */
#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0_ID 0
#define PIN1_ID 1
#define PIN2_ID 2
#define PIN3_ID 3
#define PIN4_ID 4
#define PIN5_ID 5
#define PIN6_ID 6
#define PIN7_ID 7

#define NUM_OF_PORTS 4
#define NUM_OF_PINS 8
/* Enums for data types*/
typedef enum
{
PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType; /* It's used for deciding the pin direction type */
typedef enum
{
PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType; /* It's used for deciding the port direction type */

/* functions prototypes */

/* Description
 * It setup the pin direction (input or output)
 * if the port or pin number isn't correct , The function will not handle the
request.  */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

/* Description
It Writes the value Logic High or Logic Low on the required pin.
If the input port number or pin number are not correct, The function will not handle the
request.
If the pin is input, this function will enable/disable the internal pull-up resistor.  */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/* Description
It Reads and returns the value for the required pin, it should be Logic High or Logic Low.
If the input port number or pin number are not correct, The function will return Logic
Low.*/
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);

/* Description
It Setups the direction of the required port all pins input/output.
If the direction value is PORT_INPUT all pins in this port should be input pins.
If the direction value is PORT_OUTPUT all pins in this port should be output pins.
If the input port number is not correct, The function will not handle the request.*/
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction);

/* Description
It Writes the value Logic High or Logic Low on the required pin.
If the input port number or pin number are not correct, The function will not handle the
request.
If the pin is input, this function will enable/disable the internal pull-up resistor.  */
void GPIO_writePort(uint8 port_num, uint8 value);

/* Description
It Reads and returns the value of the required port.
If the input port number is not correct, The function will return ZERO value. */
uint8 GPIO_readPort(uint8 port_num);

#endif /* GPIO_DRIVER_H_ */
