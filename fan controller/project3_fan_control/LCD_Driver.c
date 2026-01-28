/*
 * LCD_Driver.c
 *
 *  Created on: Oct 3, 2022
 *      Author: basmala sherief
 */
#include "LCD_driver.h"
#include "gpio_driver.h"
#include "common_macros.h"
#include <avr/delay.h>
/* functions definitions */

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void){
	/* set RS ,E as output */
	GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_RW_PORT_ID,LCD_RW_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);
	_delay_ms(20);
#if(LCD_DATA_BITS_MODE==4)
	/* use 4 bits 2lines 5x7 dots mode */
	LCD_sendCommand(LCD_SET_FOUR_BITS_TWO_LINES_MODE);
	/* set 4 pins as output in the data port */
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB4_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB5_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB6_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT,LCD_DB7_PIN_ID,PIN_OUTPUT);
	/* Send for 4 bit initializations */
	LCD_sendCommand(LCD_GO_HOME);
#elif(LCD_DATA_BITS_MODE==8)
	/* use 8 bits 2lines 5x7 dots mode */
	LCD_sendCommand(LCD_SET_EIGHT_BITS_TWO_LINES_MODE);
	/* set the whole data port as output*/
	GPIO_setupPortDirection(LCD_DATA_PORT,PORT_OUTPUT);
#endif
	/* Turn cursor off and clear screen at the beginning*/
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_SCREEN);
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command){

	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW); /* command mode rs=0 */
	GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_LOW); /* write mode rw=0 */
    _delay_ms(1); /* delay for processing Tas = 50ns */
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* enable E */
    _delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
#if(LCD_DATA_BITS_MODE==4)
    /* out the command to 4 pins of data bus */
    GPIO_writePin(LCD_DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5_PIN_ID,GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6_PIN_ID,GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7_PIN_ID,GET_BIT(command,7));
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* disable E */
    _delay_ms(1); /* delay for processing Th = 13ns */
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* enable E */
    _delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
    GPIO_writePin(LCD_DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5_PIN_ID,GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6_PIN_ID,GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7_PIN_ID,GET_BIT(command,3));
    _delay_ms(1);/* delay for processing Tdsw = 100ns */
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* disable E */
    _delay_ms(1); /* delay for processing Th = 13ns */
#elif(LCD_DATA_BITS_MODE==8)
    GPIO_writePort(LCD_DATA_PORT,command); /* out the command to whole data bus */
    _delay_ms(1);/* delay for processing Tdsw = 100ns */
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* disable E */
    _delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

void LCD_displayCharacter(uint8 data){
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH); /* Display mode rs=1 */
	GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID,LOGIC_LOW); /* write mode rw=0 */
    _delay_ms(1); /* delay for processing Tas = 50ns */
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* enable E */
    _delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
#if(LCD_DATA_BITS_MODE==4)
    /* out the command to 4 pins of data bus */
    GPIO_writePin(LCD_DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(data,4));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5_PIN_ID,GET_BIT(data,5));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6_PIN_ID,GET_BIT(data,6));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7_PIN_ID,GET_BIT(data,7));
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* disable E */
    _delay_ms(1); /* delay for processing Th = 13ns */
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_HIGH); /* enable E */
    _delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */
    GPIO_writePin(LCD_DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(data,0));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB5_PIN_ID,GET_BIT(data,1));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB6_PIN_ID,GET_BIT(data,2));
	GPIO_writePin(LCD_DATA_PORT,LCD_DB7_PIN_ID,GET_BIT(data,3));
    _delay_ms(1);/* delay for processing Tdsw = 100ns */
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* disable E */
    _delay_ms(1); /* delay for processing Th = 13ns */
#elif(LCD_DATA_BITS_MODE==8)
    GPIO_writePort(LCD_DATA_PORT,data); /* out the command to whole data bus */
    _delay_ms(1);/* delay for processing Tdsw = 100ns */
    GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID,LOGIC_LOW); /* disable E */
    _delay_ms(1); /* delay for processing Th = 13ns */
#endif
}
/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *str){
	uint8 i =0;
	while(str[i]!='\0')
	{
		LCD_displayCharacter(str[i]);
		i++;
	}
}
/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row, uint8 column){
	uint8 lcd_memmory_address;
	/* calculate the required cursor address */
	switch(row){
	case 0:
		lcd_memmory_address=column;
		break;
	case 1:
		lcd_memmory_address=column+0x40;
		break;
	case 2:
		lcd_memmory_address=column+0x10;
		break;
	case 3:
		lcd_memmory_address=column+0x50;
		break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memmory_address|LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row, uint8 column,const char *str){
	LCD_moveCursor(row,column); /* go to this specific address */
	LCD_displayString(str); /* display */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data){
	char buff[16]; /* to hold the asci result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); /* to display */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void){
	LCD_sendCommand(LCD_CLEAR_SCREEN);
}
