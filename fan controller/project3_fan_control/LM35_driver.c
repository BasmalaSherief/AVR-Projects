/*
 * LM35_driver.c
 *
 *  Created on: Oct 8, 2022
 *      Author: basmala sherief
 */
#include "adc_driver.h"
#include "lm35_driver.h"
/* functions definitions */
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemperature(void){
	uint8 temp_value=0;
	uint16 adc_value=0;
	adc_value=ADC_readChannel(CHANNEL_ID);
	temp_value = (uint8)(((uint32)adc_value*LM35_MAX_TEMP*ADC_VOLT)/(ADC_MAX_VALUE*LM35_MAX_VOLT));
	return temp_value;
}
