 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: led.c
 *
 * Description: Source file for the LED driver
 *
 * Author: Omar Ashraf
 *
 *******************************************************************************/

#include "led.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void LEDS_Init(void)
{
	GPIO_setupPinDirection(LED1_PORT, LED1_PIN , PIN_OUTPUT);
	GPIO_setupPinDirection(LED2_PORT, LED2_PIN , PIN_OUTPUT);
	GPIO_setupPinDirection(LED3_PORT, LED3_PIN , PIN_OUTPUT);

	GPIO_writePin(LED1_PORT , LED1_PIN , LOGIC_LOW);
	GPIO_writePin(LED2_PORT , LED2_PIN , LOGIC_LOW);
	GPIO_writePin(LED3_PORT , LED3_PIN , LOGIC_LOW);

}

void LED_ON(LED_Number led)
{
	switch(led)
	{
	case LED_1 :
		GPIO_writePin(LED1_PORT , LED1_PIN , LOGIC_HIGH);
		break;
	case LED_2 :
		GPIO_writePin(LED2_PORT , LED2_PIN , LOGIC_HIGH);
		break;
	case LED_3 :
		GPIO_writePin(LED3_PORT , LED3_PIN , LOGIC_HIGH);
		break;
	}
}


void LED_OFF(LED_Number led)
{
	switch(led)
	{
	case LED_1 :
		GPIO_writePin(LED1_PORT , LED1_PIN , LOGIC_LOW);
		break;
	case LED_2 :
		GPIO_writePin(LED2_PORT , LED2_PIN , LOGIC_LOW);
		break;
	case LED_3 :
		GPIO_writePin(LED3_PORT , LED3_PIN , LOGIC_LOW);
		break;
	}
}

void LEDS_all_off(void)
{
	GPIO_writePin(LED1_PORT , LED1_PIN , LOGIC_LOW);
	GPIO_writePin(LED2_PORT , LED2_PIN , LOGIC_LOW);
	GPIO_writePin(LED3_PORT , LED3_PIN , LOGIC_LOW);
}
