/***
 * 
 * Example code: This code is a simple program that turn on/off a LED with a button while another LED flash.
 * 
 ***/

#include "pwm_convert.h"

// On reçoit tous les ports et tous les datas venant du protocole RS485. Le calul est fait et le signal PWM est set pour l'ensemble du
// array de PWM.
void setALL_pulsewidth(PwmOut pwm[],uint8_t data[],int size)
{
    for (int i=0;i<size;++i)
    {
        pwm[i].pulsewidth_us(calcul_pwm(data[i]));
    }
}

// On reçoit un port PWM et un data venant du protocole RS485. Le calul est fait et le signal PWM est set.
void set_pulsewidth(PwmOut pwm,uint8_t data)
{
    pwm.pulsewidth_us(calcul_pwm(data));
}

// Réception d'une valeur entre 0 et 200 où 100 est la valeur neutre. 0 = -100% et 200 = 100%
int calcul_pwm (uint8_t duty)
{
    double return_pwm;

    if (duty <=99)
    {
        return_pwm = mMinDead + ((duty-100)*(mMinDead-mMin))/100;
    } 
    else if(duty >=101 && duty <= 200)
    {
        return_pwm = mMaxDead + ((duty-100)*(mMax-mMaxDead))/100;
    }
    else
    {
        return_pwm = neutralDuty;
    }

    return return_pwm;
}

