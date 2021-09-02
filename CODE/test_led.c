#include <test_led.h>
#use delay(crystal=20000000)
#fuses HS, NOWDT, NOPROTECT, PUT, NOLVP


void main()
{
   setup_timer_2(T2_DIV_BY_16,255,1);
   setup_ccp2(CCP_PWM);
   set_tris_D(0x00);
   while(TRUE)
   {
      //TODO: User Code
      set_pwm2_duty(0);
      delay_ms(2000);
      set_pwm2_duty(64);
      delay_ms(2000);
      set_pwm2_duty(128);
      delay_ms(2000);
      set_pwm2_duty(192);
      delay_ms(2000);
      set_pwm2_duty(255);
      delay_ms(2000);
      
   }

}
