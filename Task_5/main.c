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
	DIO_voidSetPortDirection(PORT_u8D, PORT_OUT);
	DIO_voidSetPortDirection(PORT_u8A, PORT_OUT);

	SSD_t OBJ_1 = { PORT_u8D, NULL, NULL, COMMON_ANODE};
	SSD_t OBJ_2 = { PORT_u8A, NULL, NULL, COMMON_ANODE};

	u8 Local_u8CurrentVal_1 = 0;
	u8 Local_u8CurrentVal_2 = 0;


	//DIP
	SWITCH_t DIP_1 = {PORT_u8B, PIN0};
	SWITCH_u8ButtonInitialize(DIP_1);
	SWITCH_voidButtonEnablePullup(DIP_1);
	u8 Local_u8CurrentSwitch = SWITCH_u8ButtonRead(DIP_1);

	while(1){

		SSD_voidDisplayNum(OBJ_1, 0);
		SSD_voidDisplayNum(OBJ_2, 0);

		Local_u8CurrentSwitch = SWITCH_u8ButtonRead(DIP_1);

		for(u8 i = 0 ; i < 10 ; ++i){
			Local_u8CurrentSwitch = SWITCH_u8ButtonRead(DIP_1);
			if(!Local_u8CurrentSwitch){
				Local_u8CurrentVal_1 = i;
				SSD_voidDisplayNum(OBJ_1, Local_u8CurrentVal_1);
				Local_u8CurrentSwitch = SWITCH_u8ButtonRead(DIP_1);

				for(u8 j = 0 ; j < 10 ; ++j){
					Local_u8CurrentSwitch = SWITCH_u8ButtonRead(DIP_1);
					if(!Local_u8CurrentSwitch){
						Local_u8CurrentVal_2 = j;
						SSD_voidDisplayNum(OBJ_2, Local_u8CurrentVal_2);
						Local_u8CurrentSwitch = SWITCH_u8ButtonRead(DIP_1);
						_delay_ms(500);
					}
					else{
						j--;
						SSD_voidDisplayNum(OBJ_1, Local_u8CurrentVal_1);
						SSD_voidDisplayNum(OBJ_2, Local_u8CurrentVal_2);
					}
				}
			}
			else{
				i--;
				SSD_voidDisplayNum(OBJ_1, Local_u8CurrentVal_1);
				SSD_voidDisplayNum(OBJ_2, Local_u8CurrentVal_2);
			}
		}
	}
}
