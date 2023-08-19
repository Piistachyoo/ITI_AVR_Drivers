/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : ITI_AVR_Drivers                                    	 */
/* File          : main.c                           					 */
/* Date          : Aug 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "../HAL/Seven_Segment/SS_interface.h"
#include <util/delay.h>
#define F_CPU 8000000UL

int main(void){
	SS_t SS1, SS2;
	uint8 index;
	for(index = 0; index < 7; index++){
		SS1.PIN[index].GPIOx = GPIOC;
		SS1.PIN[index].direction = GPIO_OUTPUT;
		SS1.PIN[index].pin = index;
	}
	SS1.mode = SS_MODE_CommonAnode;

	for(index = 0; index < 7; index++){
		SS2.PIN[index].GPIOx = GPIOD;
		SS2.PIN[index].direction = GPIO_OUTPUT;
		SS2.PIN[index].pin = index;
	}
	SS2.mode = SS_MODE_CommonCathode;

	SS_Init(&SS1);
	SS_Init(&SS2);


	while(1){
		for(index = 0; index < 10; index++){
			SS_Display(&SS1, index);
			SS_Display(&SS2, index);
			_delay_ms(500);
		}
	}
	return 0;
}
