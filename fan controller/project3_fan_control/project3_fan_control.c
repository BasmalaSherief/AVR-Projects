/*
 * project3_fan_control.c
 *
 *  Created on: Oct 8, 2022
 *      Author: basmala sherief
 */
#include "lcd_driver.h"
#include "ADC_driver.h"
#include "lm35_driver.h"
#include "dc-motor_driver.h"
int main(void)
{
	uint8 temp;
	LCD_init(); /*initialize lcd */
	ADC_ConfigType config = {INTERNAL,pre_8};
	ADC_init(&config);
	DcMotor_init();
	/*Display the string */
	LCD_displayStringRowColumn(0,4,"Fan is ");
	LCD_displayStringRowColumn(1,4,"Temp =    C");
	while(1)
	{
		temp=LM35_GetTemperature();
		if((temp>=0)&&(temp<30))
		{
			LCD_moveCursor(0,11);
			LCD_displayString("OFF");
			LCD_moveCursor(1,11);
			if(temp < 10)
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
				LCD_displayCharacter(' ');
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
			}
			DcMotor_Rotate(STOP,0);
		}
	    else if((temp>=30)&&(temp<60))
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,11);
            LCD_intgerToString(temp);
            LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,25);
		}
		else if((temp>=60)&&(temp<90))
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,11);
            LCD_intgerToString(temp);
            LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,50);
		}
		else if((temp>=90)&&(temp<120))
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,11);
            LCD_intgerToString(temp);
            LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,75);
		}
		else if(temp>=120)
		{
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
			LCD_moveCursor(1,11);
            LCD_intgerToString(temp);
            LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,100);
		}
		else
		{
			LCD_moveCursor(0, 11);
			LCD_displayStringRowColumn(0, 4, "OFF");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(0);
			DcMotor_Rotate(STOP, 0);
		}
	}
}

