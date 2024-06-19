 /******************************************************************************
 *
 * Module: Timer1
 *
 * File Name: timer1.c
 *
 * Description: Source file for the Timer1 AVR driver
 *
 * Author: Omar Ashraf
 *
 *******************************************************************************/

#include"timer1.h"
#include "gpio.h"
#include"avr/io.h" /* To use Timer1 Registers */
#include <avr/interrupt.h> /* For Timer1 ISR */
#include "std_types.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(TIMER1_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the Interrupt occurs */
		(*g_callBackPtr)();
	}
}

ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the Interrupt occurs */
		(*g_callBackPtr)();
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void Timer1_init(const Timer1_ConfigType * Config_Ptr)
{
	switch(Config_Ptr->mode)
	{
	case NORMAL_MODE:
		TCNT1  = Config_Ptr->initial_value;
		TIMSK  = (1<<TOIE1);
		TCCR1A = (1<<FOC1A) | (1<<FOC1B);
		TCCR1B = Config_Ptr->prescaler;
		break;
	case COMPARE_MODE:
		TCCR1A = (1<<FOC1A);
		TCCR1B = (1<<WGM12);
		TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->prescaler);
		TCNT1  = Config_Ptr->initial_value;
		OCR1A  = Config_Ptr->compare_value;
		TIMSK |= (1<<OCIE1A);
		break;
	case PWM_MODE:
		/* Make OC1A pin as output */
		GPIO_setupPinDirection(PORTD_ID , PIN5_ID , PIN_OUTPUT);

		TCNT1  = 0;
		ICR1   = Config_Ptr->top_value; /* Set TOP count for timer1 in ICR1 register */
		OCR1A  = Config_Ptr->compare_value;
	    TCCR1A = (1<<WGM11) | (1<<COM1A1);
		TCCR1B = (1<<WGM12) | (1<<WGM13);
		TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->prescaler);
	}
}

void Timer1_deInit(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	TIMSK = 0;
}

void Timer1_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}



