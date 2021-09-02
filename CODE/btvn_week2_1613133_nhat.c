#include <btvn_week2_1613133_nhat.h>
int1 n;
void main()
{
   set_tris_A(0x00);
   set_tris_B(0x00);
   set_tris_C(0x00);
   set_tris_D(0x00);
   set_tris_E(0x00);
   set_tris_F(0x00);
   set_tris_G(0x00);
   set_tris_H(0x00);
   set_tris_J(0x02);
   
   output_B(0);
   output_C(0);
   output_D(0);
   output_E(0);
   output_F(0);
   output_G(0);
   output_H(0);
   

   while(TRUE)
   {
      n = input(Pin_J1);
      if(n==1)
      {
      output_B(0x0f);
      output_C(0xfb);
      output_D(0x0f);
      output_E(0xdf);
      output_F(0x0f);
      output_G(0xdf);
      output_H(0xdf);
      }
      else
      {
      output_B(0x00);
      output_C(0x00);
      output_D(0x00);
      output_E(0x00);
      output_F(0x00);
      output_G(0x00);
      output_H(0x00);
      }
   }

}
