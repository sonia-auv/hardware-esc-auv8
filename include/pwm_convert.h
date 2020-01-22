#ifndef _PWM_CONVERT_H
#define _PWM_CONVERT_H

#include "mbed.h"

#define mMinDead 1470
#define mMaxDead 1530
#define neutralDuty 1500
#define mMax 1900
#define mMin 1100

// Private
int calcul_pwm(uint8_t duty);

// Public
void setALL_pulsewidth(PwmOut pwm[],uint8_t data[],int size);
void set_pulsewidth(PwmOut pwm,uint8_t data);

#endif //_PWM_CONVERT_H