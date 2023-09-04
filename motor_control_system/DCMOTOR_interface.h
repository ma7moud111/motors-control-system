/**********************************************************************/
/**********************************************************************/
/**************	   Author: Mahmoud Sayed	***************************/
/**************	   Layer: HAL 				***************************/
/**************	   SWC/Driver: DC Motor		***************************/
/**************	   Version: 1.00			***************************/
/**********************************************************************/
/**********************************************************************/

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

void DCMOTOR_voidRotateClockWise(u8 Copy_u8Port, u8 Copy_u8PinHigh, u8 Copy_u8PinLow);

void DCMOTOR_voidRotateCounterClockWise(u8 Copy_u8Port, u8 Copy_u8PinHigh, u8 Copy_u8PinLow);

void DCMOTOR_voidStopDCMotor(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2);

#endif
