/*
 * ADC_driver.h
 *
 *  Created on: Oct 4, 2022
 *      Author: basmala sherief
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "std_types.h"

/* definitions */
#define ADC_MAX_VALUE 1023
#define ADC_VOLT 2.56

/* Structures and enums */
typedef enum { /* to configure the reference volt */
	AREF,AVCC,INTERNAL=3
}ADC_ReferanceVoltage;
typedef enum { /* to configure the prescaler */
	pre_2=1,pre_4,pre_8,pre_16,pre_32,pre_64,pre_128
}ADC_Prescaler;
typedef struct{
	ADC_ReferanceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;
/* functions prototypes */
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 Ch_num);

#endif /* ADC_DRIVER_H_ */
