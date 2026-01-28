/*
 * LCD_Driver.h
 *
 *  Created on: Oct 3, 2022
 *      Author: basmala sherief
 */

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_
#include "std_types.h"
/* Definitions */
/* LCD bit mode , choose 4 bit mode or 8 bit mode */
#define LCD_DATA_BITS_MODE 8
#if ((LCD_DATA_BITS_MODE !=4)&&(LCD_DATA_BITS_MODE !=8))
#error "wrong number , choose between 4 and 8"
#endif
/* LCD hw ports and pins */
#define LCD_RS_PORT_ID PORTD_ID
#define LCD_RS_PIN_ID PIN0_ID
#define LCD_RW_PORT_ID PORTD_ID
#define LCD_RW_PIN_ID PIN1_ID
#define LCD_E_PORT_ID PORTD_ID
#define LCD_E_PIN_ID PIN2_ID
#define LCD_DATA_PORT PORTC_ID
#if (LCD_DATA_BITS_MODE ==4)
#define LCD_DB4_PIN_ID PIN3_ID
#define LCD_DB5_PIN_ID PIN4_ID
#define LCD_DB6_PIN_ID PIN5_ID
#define LCD_DB7_PIN_ID PIN6_ID
#endif
/* LCD commands */
#define LCD_CLEAR_SCREEN 0x01
#define LCD_GO_HOME 0x02
#define LCD_CURSOR_OFF 0x0C
#define LCD_CURSOR_ON 0x0E
#define LCD_SET_CURSOR_LOCATION 0x80
#define LCD_SET_FOUR_BITS_TWO_LINES_MODE 0x28
#define LCD_SET_EIGHT_BITS_TWO_LINES_MODE 0x38
#define LCD_SET_FOUR_BITS_TWO_LINES_MODE_INIT1 0x33
#define LCD_SET_FOUR_BITS_TWO_LINES_MODE_INIT2 0x32

/* functions prototypes */

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *str);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row, uint8 column);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row, uint8 column,const char *str);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);

#endif /* LCD_DRIVER_H_ */
