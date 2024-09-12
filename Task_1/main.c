/*
 * main.c
 *
 *  Created on: Sep 9, 2024
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

	// SSD
	DIO_voidSetPortDirection(PORT_u8A, PORT_OUT);
	DIO_voidSetPinDirection(PORT_u8C, PIN7, PIN_OUT);
	SSD_t OBJ = {PORT_u8A, PORT_u8C, PIN7, COMMON_ANODE};
	SSD_voidEnableDisable(OBJ, ENABLE);
	SSD_voidDisplayNum(OBJ, 0);
	u8 Local_u8SSDCount = 0;

	//SWITCH
	SWITCH_t DIP1 = {PORT_u8B, PIN0};
	SWITCH_u8ButtonInitialize(DIP1);
	SWITCH_voidButtonEnablePullup(DIP1);
	u8 Local_u8PrevSwitch = SWITCH_u8ButtonRead(DIP1);

	//LED
	LEDInitialize(PORT_u8D, PIN0);
	LED_voidOff(PORT_u8D, PIN0);

	while(1){
		while (1) {
			u8 Local_u8CurrentSwitch = SWITCH_u8ButtonRead(DIP1);
			if(Local_u8SSDCount < 9){
				if (Local_u8CurrentSwitch != Local_u8PrevSwitch) {
					Local_u8SSDCount++;
					if (Local_u8CurrentSwitch) { // on -> off
						LED_voidOff(PORT_u8D, PIN0);
						SSD_voidDisplayNum(OBJ, Local_u8SSDCount);
					} else { //off -> on
						LED_voidOn(PORT_u8D, PIN0);
						SSD_voidDisplayNum(OBJ, Local_u8SSDCount);

					}
					Local_u8PrevSwitch = Local_u8CurrentSwitch;
				}
			}
			else if(Local_u8SSDCount == 9){
				break;
			}
		}
		LED_voidOn(PORT_u8D, PIN0);
		SSD_voidDisplayNum(OBJ, 9);

	}
}


