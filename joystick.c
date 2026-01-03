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



/*roll ve pitch degerleri direkt kullanilacak yaw ve altitude degerleri
 * saniyelik cinsden kullanilacak ex: 2m/sn veya 120 derece /sn
 */
void ConvertToAngle(int8_t *roll, int8_t *pitch, int8_t *yaw, int8_t *altitude,uint16_t x,uint16_t y,uint16_t xx,uint16_t yy){///yaw ve altitude icin degerler yollanacak.
    int RealValueToRoll = adcValues[0] - x;//x y xx yy getadcvaluesden alınan ilk degerler.
	*roll = 30*RealValueToRoll/2020;
	if (*roll >= 30) {
		*roll=30;
	}else if (*roll<=-30) {
		*roll = -30;
	}

	int RealValueToPitch = adcValues[1] - y;
	*pitch = 30*RealValueToPitch/2020;
	if (*pitch >=30) {
		*pitch =30;
	}else if (*pitch <= -30) {
		*pitch = -30;
	}

	int RealValueToYaw = adcValues[2] - xx;
	*yaw = (120*RealValueToYaw/2020) * -1;
	if (*yaw >= 120) {
		*yaw=120;
	}else if (*yaw<=-120) {
		*yaw = -120;
	}

	int RealValueToAltitude =adcValues[3] - yy;
	*altitude = 3*RealValueToAltitude/2000;
	if (*altitude >= 3) {
		*altitude=3;
	}else if (*altitude<=-3) {
		*altitude = -3;
	}



}












