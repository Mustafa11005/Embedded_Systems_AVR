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
	// DIP
	SWITCH_t DIP1 = {PORT_u8B, PIN0};
	SWITCH_t DIP2 = {PORT_u8B, PIN1};
	SWITCH_t DIP3 = {PORT_u8B, PIN2};
	SWITCH_t DIP4 = {PORT_u8B, PIN3};
	SWITCH_t DIP5 = {PORT_u8B, PIN4};
	SWITCH_t DIP6 = {PORT_u8B, PIN5};
	SWITCH_t DIP7 = {PORT_u8B, PIN6};
	SWITCH_t DIP8 = {PORT_u8B, PIN7};

	SWITCH_u8ButtonInitialize(DIP1);
	SWITCH_u8ButtonInitialize(DIP2);
	SWITCH_u8ButtonInitialize(DIP3);
	SWITCH_u8ButtonInitialize(DIP4);
	SWITCH_u8ButtonInitialize(DIP5);
	SWITCH_u8ButtonInitialize(DIP6);
	SWITCH_u8ButtonInitialize(DIP7);
	SWITCH_u8ButtonInitialize(DIP8);

	SWITCH_voidButtonEnablePullup(DIP1);
	SWITCH_voidButtonEnablePullup(DIP2);
	SWITCH_voidButtonEnablePullup(DIP3);
	SWITCH_voidButtonEnablePullup(DIP4);
	SWITCH_voidButtonEnablePullup(DIP5);
	SWITCH_voidButtonEnablePullup(DIP6);
	SWITCH_voidButtonEnablePullup(DIP7);
	SWITCH_voidButtonEnablePullup(DIP8);

	// LED
	LEDInitializeAll(PORT_u8A);
	DIO_voidGroundVcc(PORT_u8D, PIN0, GND);

	while(1){
		u8 Local_u8SwitchState_1 = SWITCH_u8ButtonRead(DIP1);
		u8 Local_u8SwitchState_2 = SWITCH_u8ButtonRead(DIP2);
		u8 Local_u8SwitchState_3 = SWITCH_u8ButtonRead(DIP3);
		u8 Local_u8SwitchState_4 = SWITCH_u8ButtonRead(DIP4);
		u8 Local_u8SwitchState_5 = SWITCH_u8ButtonRead(DIP5);
		u8 Local_u8SwitchState_6 = SWITCH_u8ButtonRead(DIP6);
		u8 Local_u8SwitchState_7 = SWITCH_u8ButtonRead(DIP7);
		u8 Local_u8SwitchState_8 = SWITCH_u8ButtonRead(DIP8);

		if(!Local_u8SwitchState_1){
			LED_voidOn(PORT_u8A, PIN0);
		}
		else if(Local_u8SwitchState_1){
			LED_voidOff(PORT_u8A, PIN0);
		}
		if(!Local_u8SwitchState_2){
			LED_voidOn(PORT_u8A, PIN1);
		}
		else if(Local_u8SwitchState_2){
			LED_voidOff(PORT_u8A, PIN1);
		}
		if(!Local_u8SwitchState_3){
			LED_voidOn(PORT_u8A, PIN2);
		}
		else if(Local_u8SwitchState_3){
			LED_voidOff(PORT_u8A, PIN2);
		}
		if(!Local_u8SwitchState_4){
			LED_voidOn(PORT_u8A, PIN3);
		}
		else if(Local_u8SwitchState_4){
			LED_voidOff(PORT_u8A, PIN3);
		}
		if(!Local_u8SwitchState_5){
			LED_voidOn(PORT_u8A, PIN4);
		}
		else if(Local_u8SwitchState_5){
			LED_voidOff(PORT_u8A, PIN4);
		}
		if(!Local_u8SwitchState_6){
			LED_voidOn(PORT_u8A, PIN5);
		}
		else if(Local_u8SwitchState_6){
			LED_voidOff(PORT_u8A, PIN5);
		}
		if(!Local_u8SwitchState_7){
			LED_voidOn(PORT_u8A, PIN6);
		}
		else if(Local_u8SwitchState_7){
			LED_voidOff(PORT_u8A, PIN6);
		}
		if(!Local_u8SwitchState_8){
			LED_voidOn(PORT_u8A, PIN7);
		}
		else if(Local_u8SwitchState_8){
			LED_voidOff(PORT_u8A, PIN7);
		}
	}

}







