/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : ITI_AVR_Drivers                                    	 */
/* File          : ATMEGA32.h                           				 */
/* Date          : Aug 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef MCAL_ATMEGA32_H_
#define MCAL_ATMEGA32_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "../SERVICES/STD_LIB.h"

//----------------------------------------------
// Section: Base addresses for Peripherals
//----------------------------------------------
#define PORTA_BASE		(0x39)
#define PORTB_BASE		(0x36)
#define PORTC_BASE		(0x33)
#define PORTD_BASE		(0x30)


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint8 PIN;
	volatile uint8 DDR;
	volatile uint8 PORT;
}GPIO_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral instants
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
#define GPIOA	((GPIO_Typedef*)PORTA_BASE)
#define GPIOB	((GPIO_Typedef*)PORTB_BASE)
#define GPIOC	((GPIO_Typedef*)PORTC_BASE)
#define GPIOD	((GPIO_Typedef*)PORTD_BASE)

#endif /* MCAL_ATMEGA32_H_ */
