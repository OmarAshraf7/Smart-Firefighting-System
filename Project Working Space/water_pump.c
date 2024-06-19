 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: buzzer.c
 *
 * Description: Source file for the buzzer
 *
 * Author: Omar Ashraf
 *
 *******************************************************************************/

#include"water_pump.h"
#include"gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void Pump_init(void)
{
	/* Setup the direction for the buzzer pins as output pins */
	GPIO_setupPinDirection(PUMP_PORT_ID , PUMP_PIN_ID,PIN_OUTPUT);

	/*  Turn off the buzzer  */
	GPIO_writePin(PUMP_PORT_ID , PUMP_PIN_ID,LOGIC_LOW);
}

void Pump_Activate(void)
{
	GPIO_writePin(PUMP_PORT_ID , PUMP_PIN_ID ,LOGIC_HIGH);
}

void Pump_deActivate(void)
{
	GPIO_writePin(PUMP_PORT_ID , PUMP_PIN_ID ,LOGIC_LOW);
}
