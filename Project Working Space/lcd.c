 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Omar Ashraf
 *
 *******************************************************************************/

#include"lcd.h"
#include"gpio.h"
#include<util/delay.h> /* For the delay functions */
#include"common_macros.h" /* For GET_BIT Macro */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void LCD_init(void)
{
	/* Configure the direction for RS and E pins as output pins */
	GPIO_setupPinDirection(LCD_RS_PORT_ID, LCD_RS_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID, LCD_E_PIN_ID, PIN_OUTPUT);

	_delay_ms(20); /* delay > 15ms for power sequence */

#if(LCD_DATA_BITS_MODE == 4)
	/* Configure the 4 pins for DB as output port */
	GPIO_setupPinDirection(LCD_DB_PORT_ID, LCD_DB4_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DB_PORT_ID, LCD_DB5_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DB_PORT_ID, LCD_DB6_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DB_PORT_ID, LCD_DB7_PIN_ID, PIN_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* Initialize LCD command for 2 lines / 4-bit mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BITS_MODE == 8)
	/* Configure the DB port as output port */
	GPIO_setupPortDirection(LCD_DB_PORT_ID, PORT_OUTPUT);

	/* Initialize LCD command for 2 lines / 8-bit mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_CURSOR_OFF); /* Cursor Off at the beginning */
	LCD_sendCommand(LCD_CLEAR_DISPLAY); /* Clear screen at the beginning */
}

void LCD_sendCommand(uint8 command)
{
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_LOW); /* making RS=0 (send command) */
	_delay_ms(1); /* delay Ts = 50nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);	/* making the Enable(E) = 1 */
	_delay_ms(1); /* delay Tpw-Tdsw=290-100=190 nsec */

#if(LCD_DATA_BITS_MODE == 4)
	/* writing first 4 bits of the command on DB 4 pins */
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB4_PIN_ID , GET_BIT(command,4));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB5_PIN_ID , GET_BIT(command,5));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB6_PIN_ID , GET_BIT(command,6));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB7_PIN_ID , GET_BIT(command,7));

	_delay_ms(1); /* delay Tdsw=100nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */

	_delay_ms(1); /* delay Ts = 50nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);	/* making the Enable(E) = 1 */
	_delay_ms(1); /* delay Tpw-Tdsw=290-100=190 nsec */

	/* writing second 4 bits of the command on DB 4 pins */
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB4_PIN_ID , GET_BIT(command,0));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB5_PIN_ID , GET_BIT(command,1));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB6_PIN_ID , GET_BIT(command,2));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB7_PIN_ID , GET_BIT(command,3));

	_delay_ms(1); /* delay Tdsw=100nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay Th=13nsec */

#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DB_PORT_ID, command); /* writing the command on DB */
	_delay_ms(1); /* delay Tdsw=100nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay Th=13nsec */
#endif

}

void LCD_displayCharacter(uint8 character)
{
	GPIO_writePin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, LOGIC_HIGH); /* making RS=1 (send data) */
	_delay_ms(1); /* delay Ts = 50nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);	/* making the Enable(E) = 1 */
	_delay_ms(1); /* delay Tpw-Tdsw=290-100=190 nsec */
#if(LCD_DATA_BITS_MODE == 4)
	/* writing first 4 bits of the data(character) on DB 4 pins */
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB4_PIN_ID , GET_BIT(character,4));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB5_PIN_ID , GET_BIT(character,5));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB6_PIN_ID , GET_BIT(character,6));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB7_PIN_ID , GET_BIT(character,7));

	_delay_ms(1); /* delay Tdsw=100nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */

	_delay_ms(1); /* delay Ts = 50nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_HIGH);	/* making the Enable(E) = 1 */
	_delay_ms(1); /* delay Tpw-Tdsw=290-100=190 nsec */

	/* writing second 4 bits of the data(character) on DB 4 pins */
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB4_PIN_ID , GET_BIT(character,0));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB5_PIN_ID , GET_BIT(character,1));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB6_PIN_ID , GET_BIT(character,2));
	GPIO_writePin(LCD_DB_PORT_ID, LCD_DB7_PIN_ID , GET_BIT(character,3));

	_delay_ms(1); /* delay Tdsw=100nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay Th=13nsec */

#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DB_PORT_ID, character); /* writing the data(character) on DB */
	_delay_ms(1); /* delay Tdsw=100nsec */
	GPIO_writePin(LCD_E_PORT_ID, LCD_E_PIN_ID, LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay Th=13nsec */
#endif

}

void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}

void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address = col;
		break;
	case 1:
		lcd_memory_address = 0x40 + col;
		break;
	case 2:
		lcd_memory_address = 0x10 + col;
		break;
	case 3:
		lcd_memory_address = 0x50 + col;
		break;
	}

	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_DISPLAY); /* Send clear display command */
}

void LCD_integerToString(int data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* itoa C function convert data to its corresponding ASCII value, 10 base for decimal */
	LCD_displayString(buff); /* Display the string */
}
