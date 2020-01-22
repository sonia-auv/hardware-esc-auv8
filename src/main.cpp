/***
 *
 * Example code: This code is a simple program that turn on/off a LED with a button while another LED flash.
 *
 ***/

#include "main.h"

InterruptIn button(PC_13);
PwmOut pwm[8] = {PwmOut (PWM_1), PwmOut (PWM_2), PwmOut (PWM_3), PwmOut (PWM_4), 
  PwmOut (PWM_5), PwmOut (PWM_6), PwmOut (PWM_7), PwmOut (PWM_8)};
DigitalOut flash(LED2);
Thread threadpwm;

void function_pwm (){

  uint8_t cmd_array[1] = {CMD_PWM};
  uint8_t buffer_receiver_pwm[255];
  uint8_t nb_commands = 1;
  uint8_t size = 8;

  for (uint8_t i =0; i<size; ++i)
  {
    pwm[i].pulsewidth_us(neutralDuty);
  }

  while(1)
  {
    //flash = !flash;
    if (RS485::read(cmd_array,nb_commands,buffer_receiver_pwm) == size)
    {
      setALL_pulsewidth(pwm,buffer_receiver_pwm,size);
    }
  }
}

int main(){

  RS485::init(SLAVE_ESC_PWM);

  threadpwm.start(function_pwm);
  threadpwm.set_priority(osPriorityHigh);

}