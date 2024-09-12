/*
 * main.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Mustafa
 */

#include <util/delay.h>
#include "STDTYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SWITCH_interface.h"
#include "LED_interface.h"

void main(void){

	//LED
	LEDInitializeAll(PORT_u8A);
	LED_voidAllOff(PORT_u8A);

	while(1){
		u8 Local_u8Start = PIN0;
		for(u8 i = 0 ; i < 3 ; ++i){
			LED_voidOff(PORT_u8A, (Local_u8Start + 5 + i));
			LED_voidOn(PORT_u8A, (Local_u8Start + i));
			_delay_ms(100);
		}
		for(u8 j = 0 ; j < 5 ; ++j){
			LED_voidOff(PORT_u8A, (Local_u8Start + j));
			LED_voidOn(PORT_u8A, (Local_u8Start + 3 + j));
			_delay_ms(100);
		}
	}
}
