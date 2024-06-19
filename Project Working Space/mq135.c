 /******************************************************************************
 *
 * Module: mq135 gas sensor
 *
 * File Name: mq135.c
 *
 * Description: Source file for the gas sensor driver
 *
 * Author: Omar Ashraf
 *
 *******************************************************************************/

#include "mq135.h"
#include"adc.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
int MQ135_getGassPer(void)
{
	int gass_value = 0;
	int gass_percentage = 0;

	gass_value = ADC_Read(SENSOR_CHANNEL_ID);
	gass_percentage = ((gass_value/1023.0)*100);

	return gass_percentage;
}
