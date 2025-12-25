/*
 * joystick.c
 *
 *  Created on: Oct 18, 2025
 *      Author: emitn
 */

#include "joystick.h"

uint16_t adcValues[4];
uint16_t SecAdcValues[2];
void JoystickInit(ADC_HandleTypeDef *hadcx){
	HAL_ADC_Start_DMA(hadcx,(uint32_t*)adcValues,4);
}
void getADCValues(uint16_t *XAxisValue, uint16_t *YAxisValue,uint16_t *XxAxisValue,uint16_t *YyAxisValue){
	*XAxisValue = adcValues[0];
	*YAxisValue = adcValues[1];
	*XxAxisValue = adcValues[2];
	*YyAxisValue = adcValues[3];
}
void ConvertToAngle(int8_t *roll, int8_t *pitch){///yaw ve altitude icin degerler yollanacak.
    int RealValueToRoll = adcValues[0] - 1970;
	*roll = 30*RealValueToRoll/2020;
	if (*roll >= 30) {
		*roll=30;
	}else if (*roll<=-30) {
		*roll = -30;
	}
	int RealValueToPitch = adcValues[1]-1970;
	*pitch = 30*RealValueToPitch/2020;
	if (*pitch >=30) {
		*pitch =30;
	}else if (*pitch <= -30) {
		*pitch = -30;
	}
}












