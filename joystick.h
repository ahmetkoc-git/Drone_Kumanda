/*
 * joystick.h
 *
 *  Created on: Oct 18, 2025
 *      Author: emitn
 */

#ifndef INC_JOYSTICK_H_
#define INC_JOYSTICK_H_

#include "main.h"


void JoystickInit(ADC_HandleTypeDef *hadcx);
void getADCValues(uint16_t *XAxisValue, uint16_t *YAxisValue,uint16_t *XxAxisValue,uint16_t *YyAxisValue);
void ConvertToAngle(int8_t *roll, int8_t *pitch, int8_t *yaw, int8_t *altitude,uint16_t x,uint16_t y,uint16_t xx,uint16_t yy);
void SecondJoystickGetADC(ADC_HandleTypeDef *hadcx,int *yaw,int *updown, uint16_t *Xx,uint16_t *Yy);

#endif /* INC_JOYSTICK_H_ */
