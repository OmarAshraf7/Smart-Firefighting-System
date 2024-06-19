 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.c
 *
 * Description: Source file for the UART AVR driver
 *
 * Author: Kirelos Isaac
 *
 *******************************************************************************/

#include <avr/io.h>
#include "common_macros.h"
#include "ADC.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init()
{
	/*Select reference voltage*/
	ADMUX = (ADMUX & 0b00111111) | (ADC_Reference_Selection<<6);

	/*to select prescaler*/
	ADCSRA = (ADCSRA & 0b11111000) | (ADC_Prescaler & 0b00000111) ;

	/*to Enable ADC*/
	SET_BIT(ADCSRA,ADEN);
}

int ADC_Read(unsigned char Channel)
{
	/*to select channel*/
	ADMUX = (ADMUX &0b11100000) | (Channel & 0b00011111);

	/*to start conversion*/
	SET_BIT(ADCSRA,ADSC);

	/*to wait until coversion to complete*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF))
	{
		;
	}

	/*to clear ADIF*/
	SET_BIT(ADCSRA,ADIF);

	return (int)ADCL + (int)(ADCH<<8);
}
