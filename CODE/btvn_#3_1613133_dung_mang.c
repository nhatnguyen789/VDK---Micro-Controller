#include <btvn_#3_1613133_dung_mang.h>

int count=0,i=0;
int X[7]={0x02,0x04,0x08,0x10,0x20,0x40,0x80};
//int X[7]= {0x80,0x40,0x20,0x10,0x08,0x04,0x02};
#INT_TIMER0
void tre_r0()
{
   count =count+1;
   if(count==5)
   {
       output_B(X[i]);
       i=i+1;
       count=0;
       if(i>6)
       i=0;
   }
   set_timer0(15536);
}

void main()
{
   int1 n;
   set_tris_B(0x01);
   set_timer0(RTCC_INTERNAL|RTCC_DIV_8);
   set_timer0(15536);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   while(TRUE)
   {
      //TODO: User Code
      n=input(Pin_B0);
      if(n==1)
      {
          output_high(Pin_B0);
      }
      
   }
}
