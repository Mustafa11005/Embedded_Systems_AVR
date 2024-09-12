/*
    Layer: MCAL
    SWC: DIO
    Date: 7 SEP 2024
    Version: 1.0
    Author: Mustafa Tamer Mansour EL-Sherif
 */

#include "STDTYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"

void DIO_voidSetPortDirection(u8 Copy_u8PortNum, u8 Copy_u8PortDirection){
	switch (Copy_u8PortNum) {
	case PORT_u8A:
		DDRA = Copy_u8PortDirection;
		break;
	case PORT_u8B:
		DDRB = Copy_u8PortDirection;
		break;
	case PORT_u8C:
		DDRC = Copy_u8PortDirection;
		break;
	case PORT_u8D:
		DDRD = Copy_u8PortDirection;
		break;

	}
}

void DIO_voidSetPinDirection(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8PinDirection){
	if(Copy_u8PinDirection == PIN_OUT){
		switch (Copy_u8PortNum) {
		case PORT_u8A:
			SET_BIT(DDRA, Copy_u8PinNum);
			break;
		case PORT_u8B:
			SET_BIT(DDRB, Copy_u8PinNum);
			break;
		case PORT_u8C:
			SET_BIT(DDRC, Copy_u8PinNum);
			break;
		case PORT_u8D:
			SET_BIT(DDRD, Copy_u8PinNum);
			break;
		}
	}
	else if(Copy_u8PinDirection == PIN_IN){
		switch (Copy_u8PortNum) {
		case PORT_u8A:
			CLR_BIT(DDRA, Copy_u8PinNum);
			break;
		case PORT_u8B:
			CLR_BIT(DDRB, Copy_u8PinNum);
			break;
		case PORT_u8C:
			CLR_BIT(DDRC, Copy_u8PinNum);
			break;
		case PORT_u8D:
			CLR_BIT(DDRD, Copy_u8PinNum);
			break;
		}
	}
}

void DIO_voidSetPortValue(u8 Copy_u8PortNum, u8 Copy_u8PortValue){
	switch (Copy_u8PortNum) {
	case PORT_u8A:
		PORTA = Copy_u8PortValue;
		break;
	case PORT_u8B:
		PORTB = Copy_u8PortValue;
		break;
	case PORT_u8C:
		PORTC = Copy_u8PortValue;
		break;
	case PORT_u8D:
		PORTD = Copy_u8PortValue;
		break;

	}
}

void DIO_voidSetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8PinValue){
	if(Copy_u8PinValue == PIN_HIGH){
		switch (Copy_u8PortNum) {
		case PORT_u8A:
			SET_BIT(PORTA, Copy_u8PinNum);
			break;
		case PORT_u8B:
			SET_BIT(PORTB, Copy_u8PinNum);
			break;
		case PORT_u8C:
			SET_BIT(PORTC, Copy_u8PinNum);
			break;
		case PORT_u8D:
			SET_BIT(PORTD, Copy_u8PinNum);
			break;
		}
	}
	else if(Copy_u8PinValue == PIN_LOW){
		switch (Copy_u8PortNum) {
		case PORT_u8A:
			CLR_BIT(PORTA, Copy_u8PinNum);
			break;
		case PORT_u8B:
			CLR_BIT(PORTB, Copy_u8PinNum);
			break;
		case PORT_u8C:
			CLR_BIT(PORTC, Copy_u8PinNum);
			break;
		case PORT_u8D:
			CLR_BIT(PORTD, Copy_u8PinNum);
			break;
		}
	}

}

u8 DIO_u8GetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum){
	u8 Local_u8PinState = 0;
	switch (Copy_u8PortNum) {
	case PORT_u8A:
		Local_u8PinState = GET_BIT(PINA, Copy_u8PinNum);
		break;
	case PORT_u8B:
		Local_u8PinState = GET_BIT(PINB, Copy_u8PinNum);
		break;
	case PORT_u8C:
		Local_u8PinState = GET_BIT(PINC, Copy_u8PinNum);
		break;
	case PORT_u8D:
		Local_u8PinState = GET_BIT(PIND, Copy_u8PinNum);
		break;
	}
	return Local_u8PinState;
}

void DIO_u8SetInternalPullup(u8 Copy_u8PortNum, u8 Copy_u8PinNum)
{
	switch (Copy_u8PortNum)
	{
	case PORT_u8A:
		SET_BIT(PORTA, Copy_u8PinNum);
		break;
	case PORT_u8B:
		SET_BIT(PORTB, Copy_u8PinNum);
		break;
	case PORT_u8C:
		SET_BIT(PORTC, Copy_u8PinNum);
		break;
	case PORT_u8D:
		SET_BIT(PORTD, Copy_u8PinNum);
		break;
	default:
		break;
	}
}

void DIO_voidTogglePin(u8 Copy_u8PortNum, u8 Copy_u8PinNum)
{
	switch(Copy_u8PortNum)
	{
	case PORT_u8A:
		if(GET_BIT(PINA, Copy_u8PinNum) == PIN_HIGH){
			CLR_BIT(PORTA, Copy_u8PinNum);
		}
		else if(GET_BIT(PINA, Copy_u8PinNum) == PIN_LOW){
			SET_BIT(PORTA, Copy_u8PinNum);
		}
		break;
	case PORT_u8B:
		if(GET_BIT(PINB, Copy_u8PinNum) == PIN_HIGH){
			CLR_BIT(PORTB, Copy_u8PinNum);
		}
		else if(GET_BIT(PINB, Copy_u8PinNum) == PIN_LOW){
			SET_BIT(PORTB, Copy_u8PinNum);
		}
		break;
	case PORT_u8C:
		if(GET_BIT(PINC, Copy_u8PinNum) == PIN_HIGH){
			CLR_BIT(PORTC, Copy_u8PinNum);
		}
		else if(GET_BIT(PINC, Copy_u8PinNum) == PIN_LOW){
			SET_BIT(PORTC, Copy_u8PinNum);
		}
		break;
	case PORT_u8D:
		if(GET_BIT(PIND, Copy_u8PinNum) == PIN_HIGH){
			CLR_BIT(PORTD, Copy_u8PinNum);
		}
		else if(GET_BIT(PIND, Copy_u8PinNum) == PIN_LOW){
			SET_BIT(PORTD, Copy_u8PinNum);
		}
		break;
	default:
		break;
	}
}

void DIO_voidGroundVcc(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8Mode){
	switch (Copy_u8PortNum) {
	case PORT_u8A:
		SET_BIT(DDRA, Copy_u8PinNum);
		break;
	case PORT_u8B:
		SET_BIT(DDRB, Copy_u8PinNum);
		break;
	case PORT_u8C:
		SET_BIT(DDRC, Copy_u8PinNum);
		break;
	case PORT_u8D:
		SET_BIT(DDRD, Copy_u8PinNum);
		break;
	}
	if(Copy_u8Mode == GND){
		switch (Copy_u8PortNum) {
		case PORT_u8A:
			CLR_BIT(PORTA, Copy_u8PinNum);
			break;
		case PORT_u8B:
			CLR_BIT(PORTB, Copy_u8PinNum);
			break;
		case PORT_u8C:
			CLR_BIT(PORTC, Copy_u8PinNum);
			break;
		case PORT_u8D:
			CLR_BIT(PORTD, Copy_u8PinNum);
			break;
		}
	}
	else if(Copy_u8Mode == VCC){
		switch (Copy_u8PortNum) {
		case PORT_u8A:
			SET_BIT(PORTA, Copy_u8PinNum);
			break;
		case PORT_u8B:
			SET_BIT(PORTB, Copy_u8PinNum);
			break;
		case PORT_u8C:
			SET_BIT(PORTC, Copy_u8PinNum);
			break;
		case PORT_u8D:
			SET_BIT(PORTD, Copy_u8PinNum);
			break;
		}

	}
}

