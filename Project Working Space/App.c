/*
 ================================================================================================
 Name        : App.c
 Author      : Omar Ashraf
 Description : Smart Firefighting System
 Date        : 13/05/2024
 ================================================================================================
 */

#include "avr/io.h"
#include "std_types.h"
#include "util/delay.h"
#include "gpio.h"
#include "usart.h"
#include "adc.h"
#include "timer1.h"
#include "mq135.h"
#include "water_pump.h"
#include "led.h"
#include "buzzer.h"
#include "lcd.h"

/*********************************************************************************************************
 *                      				     Definitions                                                 *
 *********************************************************************************************************/

#define COMPARE_MODE_VALUE	7812
#define TOP_VALUE			2499
#define SERVO_0_DEGREE  	124
#define SERVO_90_DEGREE  	187
#define SERVO_180_DEGREE  	250

/*********************************************************************************************************
 *                      				 Types Deceleration                                              *
 *********************************************************************************************************/

typedef enum
{
	SAFE , WARNING , DANGER
}Current_State;

/*********************************************************************************************************
 *                      				  Global Variables                                               *
 *********************************************************************************************************/

uint8 g_Safeflag = 0;
uint8 g_Warningflag = 0;
uint8 g_Dangerflag = 0;
uint8 g_Seconds = 0;
uint8 g_Minutes = 5;
uint8 g_GassPer = 0;
char Gas_Buffer[3];
char Seconds_Buffer[2];
char Miniutes_Buffer[1];

void (*Ptr_current_state) (void) = NULL_PTR;
Current_State g_CurrentState = NULL ;

/*********************************************************************************************************
 *                      				Functions Prototypes                                             *
 *********************************************************************************************************/

void system_Default(void);
void safe_state(void);
void warning_state(void);
void danger_state(void);
void get_state(void);
void update_state(void);
void Timer_CallBack(void); /* Timer1 Callback compare mode */
void open_door(void);
void close_door(void);
void Received_From_GUI(void); /* UART callback function */
void Send_State_to_GUI(void);
void Send_Time_to_GUI(void);
void Send_Gas_to_GUI(void);
void Time_Display_LCD(void);
void GAS_Display_LCD(void);

/*********************************************************************************************************
 *                      				Functions Definitions                                            *
 *********************************************************************************************************/
void system_Default(void)
{
	LEDS_all_off();
	Buzzer_off();
	Pump_deActivate();
	Timer1_deInit();
	g_Seconds = 0;
	g_Minutes = 5;
}
//======================================================================================================//
void safe_state(void)
{
	g_Warningflag = 0;
	g_Dangerflag = 0;

	if(g_Safeflag == 0)
	{
		Send_State_to_GUI();
		system_Default();
		/* green led on */
		LED_ON(LED_1);
		LCD_clearScreen();
		LCD_displayString("State: Safe");
		g_Safeflag = 1;
	}
}
//======================================================================================================//
void warning_state(void)
{
	g_Safeflag = 0;
	g_Dangerflag = 0;
	if(g_Warningflag == 0)
	{
		Send_State_to_GUI();
		system_Default();
		/* yellow led on */
		LED_ON(LED_2);
		LCD_clearScreen();
		LCD_displayString("State: Warning");
		g_Warningflag = 1;
	}
}
//======================================================================================================//
void danger_state(void)
{
	g_Safeflag = 0;
	g_Warningflag = 0;
	if(g_Dangerflag == 0)
	{
		Send_State_to_GUI();
		system_Default();
		/* red led on */
		LED_ON(LED_3);
		Buzzer_on();
		Pump_Activate();
		LCD_clearScreen();
		LCD_displayString("State: Danger");
		Timer1_ConfigType Timer1_config ={0, COMPARE_MODE_VALUE , 0 , F_CPU_1024, COMPARE_MODE};
		Timer1_init(&Timer1_config);
		Timer1_setCallBack(Timer_CallBack);
		g_Dangerflag = 1;
	}
}
//======================================================================================================//
void get_state(void)
{
	if(g_GassPer < 25)
	{
		g_CurrentState = SAFE;
		update_state();
	}
	else if(g_GassPer < 50)
	{
		g_CurrentState = WARNING;
		update_state();
	}
	else if(g_GassPer <= 100)
	{
		g_CurrentState = DANGER;
		update_state();
	}
}
//======================================================================================================//
void update_state(void)
{
	switch(g_CurrentState)
	{
	case SAFE:
		Ptr_current_state =  safe_state;
		break;
	case WARNING:
		Ptr_current_state =  warning_state;
		break;
	case DANGER:
		Ptr_current_state =  danger_state;
		break;
	}
	Ptr_current_state();
}
//======================================================================================================//
/* This function is called back(by interrupt) each 1sec. */
void Timer_CallBack(void)
{
	if(g_Seconds==0)
	{
		g_Seconds = 60;
		if(g_Minutes > 0)
		{
			g_Minutes --;
		}
	}
	g_Seconds --;

    Send_Time_to_GUI();

	/* After 5min stop the timer and close the Door */
	if(g_Minutes == 0 && g_Seconds == 0)
	{
		Timer1_deInit();
		close_door();
	}
}
//======================================================================================================//
void open_door(void)
{
	Timer1_ConfigType Timer1_config ={0, SERVO_180_DEGREE , TOP_VALUE , F_CPU_64, PWM_MODE};
	Timer1_init(&Timer1_config);
}
//======================================================================================================//
void close_door(void)
{
	Timer1_ConfigType Timer1_config ={0, SERVO_0_DEGREE , TOP_VALUE , F_CPU_64, PWM_MODE};
	Timer1_init(&Timer1_config);
}
//======================================================================================================//
void Send_State_to_GUI(void)
{
	UART_SendByte('*');
	_delay_ms(50);
	switch(g_CurrentState)
	{
	case SAFE:
		UART_SendString("0Safe");
		break;
	case WARNING:
		UART_SendString("0Warning");
		break;
	case DANGER:
		UART_SendString("0Danger");
		break;
	}
	_delay_ms(50);
	UART_SendByte(';');
}
//======================================================================================================//
void Send_Time_to_GUI(void)
{
	sprintf(Seconds_Buffer,"%d", g_Seconds);
	sprintf(Miniutes_Buffer,"%d", g_Minutes);

	UART_SendString("*1");
	_delay_ms(10);
	UART_SendString(Miniutes_Buffer);
	_delay_ms(10);
	UART_SendString(":");
	_delay_ms(10);
	UART_SendString(Seconds_Buffer);
	_delay_ms(10);
	UART_SendByte(';');
	_delay_ms(10);
}
//======================================================================================================//
void Send_Gas_to_GUI(void)
{
	sprintf(Gas_Buffer,"%d", g_GassPer);

	UART_SendString("*2");
	_delay_ms(50);
	UART_SendString(Gas_Buffer);
	_delay_ms(10);
	UART_SendByte('%');
	_delay_ms(50);
	UART_SendByte(';');
	_delay_ms(50);
}
//======================================================================================================//
void Received_From_GUI(void)
{
	uint8 received_byte = 0;
	UART_Receive_NoBlock(&received_byte);

	switch(received_byte)
	{
		case '0': //Open door
			    open_door();
				UART_SendByte('*');
				_delay_ms(50);
				UART_SendString("Door Opened");
				_delay_ms(50);
				UART_SendByte(';');
		break;

		case '1': /* close door */
				close_door();
				UART_SendByte('*');
				_delay_ms(50);
				UART_SendString("Door Closed");
				_delay_ms(50);
				UART_SendByte(';');
		break;

		case '2': /* Activate Water pump */
				Pump_Activate();
				UART_SendByte('*');
				_delay_ms(50);
				UART_SendString("Water Pump Activated");
				_delay_ms(50);
				UART_SendByte(';');
		break;

		case '3': /* Deactivate Water pump */
				Pump_deActivate();
				UART_SendByte('*');
				_delay_ms(50);
				UART_SendString("Water Pump DeActivated");
				_delay_ms(50);
				UART_SendByte(';');
		break;
	}
}
//======================================================================================================//
void Time_Display_LCD(void)
{
	LCD_moveCursor(1,9);
	LCD_integerToString(g_Minutes);
	LCD_displayStringRowColumn(1,10,":");

	if(g_Seconds < 10)
	{
		LCD_moveCursor(1,11);
		LCD_integerToString(0);
		LCD_integerToString(g_Seconds);
	}
	else
	{
		LCD_moveCursor(1,11);
		LCD_integerToString(g_Seconds);
	}
	LCD_displayStringRowColumn(1,13," ");
}
//======================================================================================================//
void GAS_Display_LCD(void)
{
	LCD_displayStringRowColumn(1,0,"Gas:");
	if(g_GassPer < 100 && g_GassPer < 10)
	{
		LCD_displayStringRowColumn(1,4,"00");
		LCD_integerToString(g_GassPer);
	}
	else if(g_GassPer < 100)
	{
		LCD_displayStringRowColumn(1,4,"0");
		LCD_integerToString(g_GassPer);
	}
	else
	{
		LCD_integerToString(g_GassPer);
	}
	LCD_displayStringRowColumn(1,7,"%");
}

/*********************************************************************************************************
 *                      					Main Function                                                *
 *********************************************************************************************************/

int main (void)
{
	/* I-bit enable (global interrupts) */
	SREG |= (1<<7);

	UART_Init();
	UART_RX_SetCallBack(Received_From_GUI);
	UART_RX_InterruptEnable();

	ADC_init();
	LCD_init();
	LEDS_Init();
	Buzzer_init();
	Pump_init();

	/* Initial State (No gass) */
	g_CurrentState = SAFE;
	Ptr_current_state = safe_state;
	Ptr_current_state();
	while(1)
	{
		g_GassPer = MQ135_getGassPer();
		Send_Gas_to_GUI();
		GAS_Display_LCD();
		get_state();
		if(g_CurrentState == DANGER)
		{
			Time_Display_LCD();
		}

	}
}

