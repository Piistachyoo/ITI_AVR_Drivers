/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : ITI_AVR_Drivers                                    	 */
/* File          : main.c                           					 */
/* Date          : Aug 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KEYPAD/keypad_interface.h"
#include "util/delay.h"
GPIO_Typedef *mygpio = GPIOC;



int main(void){
	uint8 pressed_key;
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

	KPD_t KPD1;
	for(uint8 i = 0; i < 4; i++){
		KPD1.row[i].GPIOx = GPIOC;
		KPD1.col[i].GPIOx = GPIOC;
		KPD1.row[i].direction = GPIO_INPUT;
		KPD1.col[i].direction = GPIO_OUTPUT;
		KPD1.row[i].pin = i;
		KPD1.col[i].pin = i+4;
		KPD1.row[i].default_state = GPIO_STATE_HIGH;
		KPD1.col[i].default_state = GPIO_STATE_HIGH;
	}
	keypad_init(&KPD1);
	while(1){
		keypad_Get_Pressed_Key(&KPD1, &pressed_key);
		if('F' != pressed_key)
			LCD_Send_Char(&LCD2, pressed_key);
	}
	return 0;
}

