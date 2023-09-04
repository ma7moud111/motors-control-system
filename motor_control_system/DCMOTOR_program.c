#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "DCMOTOR_interface.h"

void DCMOTOR_voidRotateClockWise(u8 Copy_u8Port, u8 Copy_u8PinHigh, u8 Copy_u8PinLow)
{
	DIO_u8SetPinValue(Copy_u8Port, Copy_u8PinLow, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8Port, Copy_u8PinHigh, DIO_u8PIN_HIGH);
	
}

void DCMOTOR_voidRotateCounterClockWise(u8 Copy_u8Port, u8 Copy_u8PinHigh, u8 Copy_u8PinLow)
{
	DIO_u8SetPinValue(Copy_u8Port, Copy_u8PinLow, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8Port, Copy_u8PinHigh, DIO_u8PIN_HIGH);
}

void DCMOTOR_voidStopDCMotor(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2)
{
	DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin1, DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin2, DIO_u8PIN_LOW);
}
