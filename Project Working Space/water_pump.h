 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.h
 *
 * Description: Header file for the buzzer
 *
 * Author: Omar Ashraf
 *
 *******************************************************************************/

#ifndef WATER_PUMP_H_
#define WATER_PUMP_H_

#include"std_types.h"

/*******************************************************************************
 *                      Definitions and Static Configurations                  *
 *******************************************************************************/

#define PUMP_PORT_ID				PORTD_ID
#define PUMP_PIN_ID					PIN7_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction for the water pump pin as output pin through the GPIO driver.
 * Turn off the water pump through the GPIO.
 */
void Pump_init(void);

/*
 * Description :
 * Function to enable the water pump through the GPIO.
 */
void Pump_Activate(void);

/*
 * Description :
 * Function to disable the water pump through the GPIO.
 */
void Pump_deActivate(void);

#endif /* WATER_PUMP_H_ */
