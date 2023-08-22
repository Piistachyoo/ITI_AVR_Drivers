/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : ITI_AVR_Drivers                                    	 */
/* File          : main.c                           					 */
/* Date          : Aug 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "../HAL/LCD/LCD_interface.h"
#include "util/delay.h"
GPIO_Typedef *mygpio = GPIOC;

uint8 o[] = {
		  0x00,
		  0x00,
		  0x07,
		  0x04,
		  0x1F,
		  0x00,
		  0x00,
		  0x00
		};

uint8 meem[] = {
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x1F,
		  0x0A,
		  0x0E,
		  0x00
		};

uint8 r[] = {
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x07,
		  0x04,
		  0x08,
		  0x10
		};

uint8 meem_new[] = {
		  0x00,
		  0x00,
		  0x00,
		  0x00,
		  0x1F,
		  0x05,
		  0x07,
		  0x00
		};

uint8 h[] = {
		  0x00,
		  0x00,
		  0x0C,
		  0x02,
		  0x1F,
		  0x00,
		  0x00,
		  0x00
		};

uint8 d[] = {
		  0x00,
		  0x00,
		  0x04,
		  0x04,
		  0x1F,
		  0x00,
		  0x00,
		  0x00
		};


int main(void){
	LCD_t LCD2;
	LCD2.mode = LCD_4BIT;
	LCD2.Display_Mode = LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF;
	LCD2.Entry_Mode = LCD_ENTRY_MODE_INC_SHIFT_OFF;
	LCD2.RS_PIN.GPIOx = GPIOD;
	LCD2.RS_PIN.direction = GPIO_OUTPUT;
	LCD2.RS_PIN.pin = GPIO_PIN_3;
	LCD2.RS_PIN.default_state = GPIO_STATE_LOW;
	LCD2.RW_PIN.GPIOx = GPIOD;
	LCD2.RW_PIN.direction = GPIO_OUTPUT;
	LCD2.RW_PIN.pin = GPIO_PIN_4;
	LCD2.RW_PIN.default_state = GPIO_STATE_LOW;
	LCD2.EN_PIN.GPIOx = GPIOD;
	LCD2.EN_PIN.direction = GPIO_OUTPUT;
	LCD2.EN_PIN.pin = GPIO_PIN_5;
	LCD2.EN_PIN.default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[0].GPIOx = GPIOD;
	LCD2.D_PINS[0].direction = GPIO_OUTPUT;
	LCD2.D_PINS[0].pin = GPIO_PIN_6;
	LCD2.D_PINS[0].default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[1].GPIOx = GPIOD;
	LCD2.D_PINS[1].direction = GPIO_OUTPUT;
	LCD2.D_PINS[1].pin = GPIO_PIN_7;
	LCD2.D_PINS[1].default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[2].GPIOx = GPIOB;
	LCD2.D_PINS[2].direction = GPIO_OUTPUT;
	LCD2.D_PINS[2].pin = GPIO_PIN_7;
	LCD2.D_PINS[2].default_state = GPIO_STATE_LOW;
	LCD2.D_PINS[3].GPIOx = GPIOB;
	LCD2.D_PINS[3].direction = GPIO_OUTPUT;
	LCD2.D_PINS[3].pin = GPIO_PIN_6;
	LCD2.D_PINS[3].default_state = GPIO_STATE_LOW;
	LCD_Init(&LCD2);
//	LCD_Send_String(&LCD2, "OMAR YAMANY");
	LCD_Save_Special_Character(&LCD2, 0, o);
	LCD_Save_Special_Character(&LCD2, 1, meem);
	LCD_Save_Special_Character(&LCD2, 2, r);
	LCD_Save_Special_Character(&LCD2, 3, meem_new);
	LCD_Save_Special_Character(&LCD2, 4, h);
	LCD_Save_Special_Character(&LCD2, 5, d);

	LCD_Send_Char_Pos(&LCD2, 0, LCD_FIRST_ROW, 16);
	LCD_Send_Char_Pos(&LCD2, 1, LCD_FIRST_ROW, 15);
	LCD_Send_Char_Pos(&LCD2, 2, LCD_FIRST_ROW, 14);
	LCD_Send_Char_Pos(&LCD2, 3, LCD_FIRST_ROW, 13);
	LCD_Send_Char_Pos(&LCD2, 4, LCD_FIRST_ROW, 12);
	LCD_Send_Char_Pos(&LCD2, 1, LCD_FIRST_ROW, 11);
	LCD_Send_Char_Pos(&LCD2, 5, LCD_FIRST_ROW, 10);
	while(1){
/*		for(int i = 0; i < 10; i++){
			LCD_Shift_Display(&LCD2, LCD_SHIFT_RIGHT, 1);
			_delay_ms(200);
		}
		for(int i = 0; i < 10; i++){
			LCD_Shift_Display(&LCD2, LCD_SHIFT_LEFT, 1);
			_delay_ms(200);
		}*/
	}
	return 0;
}

