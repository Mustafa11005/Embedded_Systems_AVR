/*
    Layer: HAL
    SWC: DIO
    Date: 7 SEP 2024
    Version: 1.0
    Author: Mustafa Tamer Mansour EL-Sherif
*/

#include "STDTYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_config.h"
#include "SSD_interface.h"
#include "SSD_private.h"

u8 SSD[10] = {
        0b00111111, // 0
        0b00000110, // 1
        0b01011011, // 2
        0b01001111, // 3
        0b01100110, // 4
        0b01101101, // 5
        0b01111101, // 6
        0b00000111, // 7
        0b01111111, // 8
        0b01101111  // 9
};

void SSD_voidEnableDisable(SSD_t Copy_tSeven, u8 Copy_u8Mode){
    if(Copy_u8Mode == ENABLE){
        if(Copy_tSeven.Type == COMMON_CATHODE){
            DIO_voidSetPinValue(Copy_tSeven.CtrlPort, Copy_tSeven.CtrlPin, PIN_LOW);
        }
        else if(Copy_tSeven.Type == COMMON_ANODE){
            DIO_voidSetPinValue(Copy_tSeven.CtrlPort, Copy_tSeven.CtrlPin, PIN_HIGH);
        }
    }
    else if(Copy_u8Mode == DISABLE){
        if(Copy_tSeven.Type == COMMON_CATHODE){
            DIO_voidSetPinValue(Copy_tSeven.CtrlPort, Copy_tSeven.CtrlPin, PIN_HIGH);
        }
        else if(Copy_tSeven.Type == COMMON_ANODE){
            DIO_voidSetPinValue(Copy_tSeven.CtrlPort, Copy_tSeven.CtrlPin, PIN_LOW);
        }
    }
}

void SSD_voidDisplayNum(SSD_t Copy_tSeven, u8 Copy_u8Num){
    if(Copy_tSeven.Type == COMMON_CATHODE){
        DIO_voidSetPortValue(Copy_tSeven.DataPort, SSD[Copy_u8Num]);
    }
    else if(Copy_tSeven.Type == COMMON_ANODE){
        DIO_voidSetPortValue(Copy_tSeven.DataPort, ~SSD[Copy_u8Num]);
    }
}
