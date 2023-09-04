#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KEYPAD_interface.h"
#include "DCMOTOR_interface.h"
#include "STEPPER_interface.h"
#include <util/delay.h>

void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();

	u8 Local_u8Option;
	STEPPER_t stp1;
	stp1.PORT = DIO_u8PORTD;
	stp1.PIN1 = DIO_u8PIN0;
	stp1.PIN2 = DIO_u8PIN1;
	stp1.PIN3 = DIO_u8PIN2;
	stp1.PIN4 = DIO_u8PIN3;
	stp1.DEGREE = 0.0;

	CLCD_voidSendString("Welcome to Motor Dashboard App");
	_delay_ms(500);

	MAIN_MENU:
	/*clear LCD*/
	CLCD_voidSendCommand(0x01);

	CLCD_voidSendString("DC motor:1");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("stepper:2");

	/*select between dc and stepper*/
	do{
		Local_u8Option = KPD_u8GetPressedKey();
	}while(Local_u8Option == 0xff);

	/*display option number on the LCD*/
	CLCD_voidSendCommand(0x01);
	CLCD_voidSendData(Local_u8Option + '0');
	_delay_ms(70);
	CLCD_voidSendCommand(0x01);

	/*if dc motor selected*/
	if(Local_u8Option == 1)
	{
		CLCD_voidSendString("Rotate CW:1");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("Rotate CCW:2");

		/*select between CW and CCW*/
		do{
			Local_u8Option = KPD_u8GetPressedKey();
		}while(Local_u8Option == 0xff);

		/*display option number on the LCD*/
		CLCD_voidSendCommand(0x01);
		CLCD_voidSendData(Local_u8Option + '0');
		if(Local_u8Option == 1)
		{
			DCMOTOR_voidRotateClockWise(DIO_u8PORTB, DIO_u8PIN6, DIO_u8PIN7);
			CLCD_voidSendCommand(0x01);

			CLCD_voidSendString("Press any key to Stop");
			do{
				Local_u8Option = KPD_u8GetPressedKey();
			}while(Local_u8Option == 0xff);
			if(Local_u8Option != 0xff)
			{
				DCMOTOR_voidStopDCMotor(DIO_u8PORTB, DIO_u8PIN6, DIO_u8PIN7);
				goto MAIN_MENU;
			}
		}
		else if(Local_u8Option == 2)
		{
			DCMOTOR_voidRotateCounterClockWise(DIO_u8PORTB, DIO_u8PIN7, DIO_u8PIN6);
			CLCD_voidSendCommand(0x01);

			CLCD_voidSendString("Press any key to Stop");
			do{
				Local_u8Option = KPD_u8GetPressedKey();
			}while(Local_u8Option == 0xff);
			if(Local_u8Option != 0xff)
			{
				DCMOTOR_voidStopDCMotor(DIO_u8PORTB, DIO_u8PIN6, DIO_u8PIN7);
				goto MAIN_MENU;
			}
		}
		else
		{
			CLCD_voidSendCommand(0x01);
			CLCD_voidSendString("Wrong option!");
			_delay_ms(200);
			goto MAIN_MENU;
		}

	}
	else if(Local_u8Option == 2)
	{
		CLCD_voidSendString("Rotate CW:1");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("Rotate CCW:2");

		/*select between CW and CCW*/
		do{
			Local_u8Option = KPD_u8GetPressedKey();
		}while(Local_u8Option == 0xff);

		/*display option number on the LCD*/
		CLCD_voidSendCommand(0x01);
		CLCD_voidSendData(Local_u8Option + '0');
		if(Local_u8Option == 1)
		{
			CLCD_voidSendCommand(0x01);

			/*enter the angle of rotation*/
			CLCD_voidSendString("Enter angle:");
			CLCD_voidGoToXY(1,0);
			while(1)
			{
				do{
					Local_u8Option = KPD_u8GetPressedKey();
				}while(Local_u8Option == 0xff);
				if(Local_u8Option != 42)
				{
					CLCD_voidSendData(Local_u8Option + '0');
					stp1.DEGREE = (stp1.DEGREE* 10.0) + Local_u8Option;
				}
				else
				{
					break;
				}
			}

			if(Local_u8Option != 0xff)
			{
				STEPPER_voidRotateClockWise(&stp1);
				CLCD_voidSendCommand(0x01);
				CLCD_voidSendString("Angle Reached");
				_delay_ms(500);
				stp1.DEGREE = 0.0;
				goto MAIN_MENU;
			}
		}
		else if(Local_u8Option == 2)
		{
			CLCD_voidSendCommand(0x01);

			/*enter the angle of rotation*/
			CLCD_voidSendString("Enter angle:");
			CLCD_voidGoToXY(1,0);
			while(1)
			{
				do{
					Local_u8Option = KPD_u8GetPressedKey();
				}while(Local_u8Option == 0xff);
				if(Local_u8Option != 42)
				{
					CLCD_voidSendData(Local_u8Option + '0');
					stp1.DEGREE = (stp1.DEGREE* 10.0) + Local_u8Option;
				}
				else
				{
					break;
				}
			}

			if(Local_u8Option != 0xff)
			{
				STEPPER_voidRotateCounterClockWise(&stp1);
				CLCD_voidSendCommand(0x01);
				CLCD_voidSendString("Angle Reached");
				_delay_ms(500);
				stp1.DEGREE = 0.0;
				goto MAIN_MENU;
			}
		}
		else
		{
			CLCD_voidSendCommand(0x01);
			CLCD_voidSendString("Wrong option!");
			_delay_ms(200);
			goto MAIN_MENU;
		}
	}


	while(1)
	{

	}
}
