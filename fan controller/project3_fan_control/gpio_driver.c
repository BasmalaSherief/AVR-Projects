/*
 * gpio_driver.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Basmala Sherief
 */
#include "gpio_driver.h"
#include "common_macros.h" /* to use macros */
#include <avr/io.h>  /* to use input/output ports */

/* Description
 * It setup the pin direction (input or output)
 * if the port or pin number isn't correct , The function will not handle the
request.  */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction){
	/* checks the input number of port or pin has exceeded the limit number */
	if((port_num>=NUM_OF_PORTS)||(pin_num>=NUM_OF_PINS))
	{
		/* nothing to do */
	}
	else
	{
		/* setup the required pin */
		switch(port_num)
		{
		case PORTA_ID:
			if(direction==PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction==PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction==PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction==PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		}
	}

}

/* Description
It Writes the value Logic High or Logic Low on the required pin.
If the input port number or pin number are not correct, The function will not handle the
request.
If the pin is input, this function will enable/disable the internal pull-up resistor.  */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value){
	/* checks the input number of port or pin has exceeded the limit number */
	if((port_num>=NUM_OF_PORTS)||(pin_num>=NUM_OF_PINS))
	{
		/* nothing to do */
	}
	else
	{
		/* write the value to the required pin */
		switch(port_num)
		{
		case PORTA_ID:
			if(value==LOGIC_HIGH)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(value==LOGIC_HIGH)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(value==LOGIC_HIGH)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(value==LOGIC_HIGH)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;
		}
	}
}

/* Description
It Reads and returns the value for the required pin, it should be Logic High or Logic Low.
If the input port number or pin number are not correct, The function will return Logic
Low.*/
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num){
	uint8 pin_value=LOGIC_LOW;
	/* checks the input number of port or pin has exceeded the limit number */
	if((port_num>=NUM_OF_PORTS)||(pin_num>=NUM_OF_PINS))
	{
		/* nothing to do */
	}
	else
		/* Read the required pin value */
	{
		switch(port_num)
				{
				case PORTA_ID:
					if(BIT_IS_SET(PINA,pin_num))
					{
						pin_value=LOGIC_HIGH;
					}
					else
					{
						pin_value=LOGIC_LOW;
					}
					break;
				case PORTB_ID:
					if(BIT_IS_SET(PINB,pin_num))
					{
						pin_value=LOGIC_HIGH;
					}
					else
					{
						pin_value=LOGIC_LOW;
					}
					break;
				case PORTC_ID:
					if(BIT_IS_SET(PINC,pin_num))
					{
						pin_value=LOGIC_HIGH;
					}
					else
					{
						pin_value=LOGIC_LOW;
					}
					break;
				case PORTD_ID:
					if(BIT_IS_SET(PIND,pin_num))
					{
						pin_value=LOGIC_HIGH;
					}
					else
					{
						pin_value=LOGIC_LOW;
					}
					break;
				}
	}
	return pin_value;
}

/*Description
* It Setups the direction of the required port all pins input/output.
If the direction value is PORT_INPUT all pins in this port should be input pins.
If the direction value is PORT_OUTPUT all pins in this port should be output pins.
If the input port number is not correct, The function will not handle the request.*/
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction){
	/* checks the input number of port has exceeded the limit number */
	if(port_num>=NUM_OF_PORTS)
	{
		/* nothing to do */
	}
	else
	{
		/* setup the required port */
		switch(port_num)
				{
				case PORTA_ID:
                    DDRA =direction;
					break;
				case PORTB_ID:
                    DDRB =direction;
					break;
				case PORTC_ID:
                    DDRC =direction;
					break;
				case PORTD_ID:
                    DDRD =direction;
					break;
				}
	}
}

/* Description
It Writes the value Logic High or Logic Low on the required pin.
If the input port number or pin number are not correct, The function will not handle the
request.
If the pin is input, this function will enable/disable the internal pull-up resistor.  */
void GPIO_writePort(uint8 port_num, uint8 value){
	/* checks the input number of port has exceeded the limit number */
	if(port_num>=NUM_OF_PORTS)
	{
		/* nothing to do */
	}
	else
	{
		/* write value to the required port */
		switch(port_num)
				{
				case PORTA_ID:
                    PORTA =value;
					break;
				case PORTB_ID:
                    PORTB =value;
					break;
				case PORTC_ID:
                    PORTC =value;
					break;
				case PORTD_ID:
                    PORTD =value;
					break;
				}
	}
}

/* Description
It Reads and returns the value of the required port.
If the input port number is not correct, The function will return ZERO value. */
uint8 GPIO_readPort(uint8 port_num){
	uint8 port_value=LOGIC_LOW;
	/* checks the input number of port has exceeded the limit number */
	if(port_num>=NUM_OF_PORTS)
	{
		return LOGIC_LOW;
	}
	else
	{
		/* read value of the required port */
		switch(port_num)
				{
				case PORTA_ID:
                    port_value=PINA;
					break;
				case PORTB_ID:
                    port_value=PINB;
					break;
				case PORTC_ID:
                    port_value=PINC;
					break;
				case PORTD_ID:
                    port_value=PIND;
					break;
				}
	}
	return port_value;
}
