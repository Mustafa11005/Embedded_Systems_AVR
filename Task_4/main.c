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

	//SSD
	DIO_voidSetPortDirection(PORT_u8C, PORT_OUT);
	SSD_t OBJ = {PORT_u8C, NULL, NULL, COMMON_ANODE};
	u8 Local_u8SSDCount = 0;
	SSD_voidDisplayNum(OBJ, Local_u8SSDCount);


	//Push-Button
	SWITCH_t PUSH1 = {PORT_u8D, PIN0};
	SWITCH_t PUSH2 = {PORT_u8D, PIN1};

	SWITCH_u8ButtonInitialize(PUSH1);
	SWITCH_u8ButtonInitialize(PUSH2);

	SWITCH_voidButtonEnablePullup(PUSH1);
	SWITCH_voidButtonEnablePullup(PUSH2);

	u8 Local_u8PrevSwitch_1 = SWITCH_u8ButtonRead(PUSH1);
	u8 Local_u8PrevSwitch_2 = SWITCH_u8ButtonRead(PUSH2);

	while(1){

		u8 Local_u8CurrentSwitch_1 = SWITCH_u8ButtonRead(PUSH1);
		u8 Local_u8CurrentSwitch_2 = SWITCH_u8ButtonRead(PUSH2);

		if (Local_u8CurrentSwitch_1 != Local_u8PrevSwitch_1) {
			if (Local_u8CurrentSwitch_1) {
				if(Local_u8SSDCount < 9){
					Local_u8SSDCount++;
				}
				else if(Local_u8SSDCount == 9){
					Local_u8SSDCount = 0;
				}
				SSD_voidDisplayNum(OBJ, Local_u8SSDCount);
			} else {
				SSD_voidDisplayNum(OBJ, Local_u8SSDCount);
			}
			Local_u8PrevSwitch_1 = Local_u8CurrentSwitch_1;
		}

		if (Local_u8CurrentSwitch_2 != Local_u8PrevSwitch_2) {
			if (Local_u8CurrentSwitch_2) {
				if(Local_u8SSDCount > 0){
					Local_u8SSDCount--;
				}
				else if(Local_u8SSDCount == 0){
					Local_u8SSDCount = 9;
				}
				SSD_voidDisplayNum(OBJ, Local_u8SSDCount);
			} else { //off -> on
				SSD_voidDisplayNum(OBJ, Local_u8SSDCount);
			}
			Local_u8PrevSwitch_2 = Local_u8CurrentSwitch_2;
		}
	}
}

