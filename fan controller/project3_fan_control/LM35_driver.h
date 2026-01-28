/*
 * LM35_driver.h
 *
 *  Created on: Oct 8, 2022
 *      Author: basmala sherief
 */

#ifndef LM35_DRIVER_H_
#define LM35_DRIVER_H_
#include "std_types.h"

/* definitions */
#define LM35_MAX_TEMP 150
#define LM35_MAX_VOLT 1.5
#define CHANNEL_ID 2

/* functions prototypes */
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemperature(void);

#endif /* LM35_DRIVER_H_ */
