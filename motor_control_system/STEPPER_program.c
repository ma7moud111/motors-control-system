#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_interface.h"
#include <util/delay.h>

void STEPPER_voidRotateClockWise(STEPPER_t* Copy_pSTEPPER_tStepper)
{
	/*calculate total number of steps*/
	f32 Local_f32NumberOfSteps;
	Local_f32NumberOfSteps = Copy_pSTEPPER_tStepper->DEGREE / STEPPER_DEGREE_PER_STEP;

	/*calculate number of iterations to reach the required angle*/
	u16 Local_u8NumberOfIterations = Local_f32NumberOfSteps / 4;

	u16 Local_u16Iter;
	for(Local_u16Iter = 0; Local_u16Iter<(u16)Local_u8NumberOfIterations; Local_u16Iter++)
	{
		/*Step 1 in stepper motor*/
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN1, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN2, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN3, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN4, DIO_u8PIN_HIGH);
		_delay_ms(20);

		/*Step 2 in stepper motor*/
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN1, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN2, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN3, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN4, DIO_u8PIN_HIGH);
		_delay_ms(20);

		/*Step 3 in stepper motor*/
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN1, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN2, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN3, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN4, DIO_u8PIN_HIGH);
		_delay_ms(20);

		/*Step 4 in stepper motor*/
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN1, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN2, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN3, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN4, DIO_u8PIN_LOW);
		_delay_ms(20);
	}
}


void STEPPER_voidRotateCounterClockWise(STEPPER_t* Copy_pSTEPPER_tStepper)
{
	/*calculate total number of steps*/
	f32 Local_u8NumberOfSteps;
	Local_u8NumberOfSteps = Copy_pSTEPPER_tStepper->DEGREE / STEPPER_DEGREE_PER_STEP;

	/*calculate number of iterations to reach the required angle*/
	u8 Local_u8NumberOfIterations = Local_u8NumberOfSteps / 4;

	u8 Local_u8Iter;
	for(Local_u8Iter = 0; Local_u8Iter<Local_u8NumberOfIterations; Local_u8Iter++)
	{
		/*Step 4 in stepper motor*/
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN4, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN3, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN2, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN1, DIO_u8PIN_HIGH);
		_delay_ms(20);

		/*Step 3 in stepper motor*/
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN4, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN3, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN2, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN1, DIO_u8PIN_HIGH);
		_delay_ms(20);

		/*Step 2 in stepper motor*/
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN4, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN3, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN2, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN1, DIO_u8PIN_HIGH);
		_delay_ms(20);


		/*Step 1 in stepper motor*/
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN4, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN3, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN2, DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Copy_pSTEPPER_tStepper->PORT, Copy_pSTEPPER_tStepper->PIN1, DIO_u8PIN_LOW);
		_delay_ms(20);

	}
}
