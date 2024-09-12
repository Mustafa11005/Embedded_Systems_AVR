/*
    Layer: HAL
    SWC: SWITCH
    Date: 9 SEP 2024
    Version: 1.0
    Author: Mustafa Tamer Mansour EL-Sherif
*/

#include "STDTYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SWITCH_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_private.h"

void SWITCH_u8ButtonInitialize(SWITCH_t Copy_tSwitch){
	DIO_voidSetPinDirection(Copy_tSwitch.CtrlPort, Copy_tSwitch.CtrlPin, PORT_IN);
}

u8 SWITCH_u8ButtonRead(SWITCH_t Copy_tSwitch){
	u8 Local_u8GetValue = 0;
	Local_u8GetValue = DIO_u8GetPinValue(Copy_tSwitch.CtrlPort, Copy_tSwitch.CtrlPin);
	return Local_u8GetValue;
}

void SWITCH_voidButtonEnablePullup(SWITCH_t Copy_tSwitch){
	DIO_u8SetInternalPullup(Copy_tSwitch.CtrlPort, Copy_tSwitch.CtrlPin);
}

u8 SWITCH_u8ToggelVar(SWITCH_t Copy_tSwitch, u8 Copy_u8PrevState){
	u8 Local_u8CurrentState = SWITCH_u8ButtonRead(Copy_tSwitch);
	if(Copy_u8PrevState == Local_u8CurrentState){
		return FALSE;
	}
	else if(Copy_u8PrevState != Local_u8CurrentState){
		return TRUE;
	}
}
