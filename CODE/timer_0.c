
#include <18F87K22.h>
#use delay(clock=16000000)   
unsigned int8 x=0, count=1;
#INT_TIMER0
void tre()
{
   count=count+1;
   if(count==5)
   {
   x=~x;
   output_B(X);
   count=0;
   }
   set_timer0(65536);
}
void main()
{
    
    set_tris_B(0x01);
    output_B(0);
    setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8);
    set_timer0(65536);
    enable_interrupts(INT_TIMER0);
    enable_interrupts(GLOBAL);
    while(TRUE)
    {
    
    }
}
