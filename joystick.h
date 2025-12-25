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
void ConvertToAngle(int8_t *roll, int8_t *pitch);
void SecondJoystickGetADC(ADC_HandleTypeDef *hadcx,int *yaw,int *updown, uint16_t *Xx,uint16_t *Yy);

#endif /* INC_JOYSTICK_H_ */
