 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: led.h
 *
 * Description: Header file for the LED driver
 *
 * Author: Omar Ashraf
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

/*******************************************************************************
 *                      Definitions and Static Configurations                  *
 *******************************************************************************/

#define LED1_PORT		PORTA_ID
#define LED1_PIN		PIN2_ID

#define LED2_PORT 		PORTA_ID
#define LED2_PIN		PIN3_ID

#define LED3_PORT 		PORTA_ID
#define LED3_PIN		PIN4_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	LED_1 , LED_2 , LED_3
}LED_Number;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Setup the LEDS pins directions through the GPIO driver.
 * Turn off the LEDS through the GPIO
 */
void LEDS_Init(void);

/*
 * Description :
 * Function to turn on a LED through the GPIO.
 */
void LED_ON(LED_Number led);

/*
 * Description :
 * Function to turn off a LED through the GPIO.
 */
void LED_OFF(LED_Number led);

/*
 * Description :
 * Function to turn off all LEDs through the GPIO.
 */
void LEDS_all_off(void);



#endif /* LED_H_ */
