#include <18F87K22.h>
int1 n;
void main()
{
   set_tris_A(0x10);
   set_tris_B(0x00);
   set_tris_C(0x00);
   set_tris_D(0x00);
   set_tris_E(0x00);
   set_tris_F(0x00);
   set_tris_G(0x00);
   set_tris_H(0x00);
   set_tris_J(0x00);
   
   output_B(0);
   output_C(0);
   output_D(0);
   output_E(0);
   output_F(0);
   output_G(0);
   output_H(0);
   

   while(TRUE)
   {
      
      n = input(Pin_A4);
      
      if(n==1)
      {
      output_B(0x0f);
      output_C(0xfb);
      output_D(0x0f);
      output_E(0xdf);
      output_G(0x0f);
      output_H(0xdf);
      output_J(0xdf);
      }
      else
      {
      output_B(0x00);
      output_C(0x00);
      output_D(0x00);
      output_E(0x00);
      output_G(0x00);
      output_H(0x00);
      output_J(0x00);
      }
   }  
}
