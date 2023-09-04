/**********************************************************************/
/**********************************************************************/
/**************	   Author: Mahmoud Sayed	***************************/
/**************	   Layer: HAL 				***************************/
/**************	   SWC/Driver: Stepper 		***************************/
/**************	   Version: 1.00			***************************/
/**********************************************************************/
/**********************************************************************/

#ifndef STEPPER_H_
#define STEPPER_H_

typedef struct{
	u8 PORT;
	u8 PIN1;
	u8 PIN2;
	u8 PIN3;
	u8 PIN4;
	f32 DEGREE;
}STEPPER_t;

void STEPPER_voidRotateClockWise(STEPPER_t* Copy_pSTEPPER_tStepper);

void STEPPER_voidRotateCounterClockWise(STEPPER_t* Copy_pSTEPPER_tStepper);

#endif
