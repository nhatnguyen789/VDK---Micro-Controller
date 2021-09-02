#include <thong_tin_sinh_vien.h>
#include<lcd.c>
#define LCD_ENABLE_PIN  PIN_D0;
#define LCD_RS PIN_D1;
#define LCD_RW PIN_D2;
#define LCD_DATA4 PIN_D4;
#define LCD_DATA5 PIN_D5;
#define LCD_DATA6 PIN_D6;
#define LCD_DATA7 PIN_D7;
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8) 

      
void main()
{
   unsigned int8 status;
   char value;
   int i=0;
   char mang[];
   set_tris_d(0x00);
   LCD_init();
   

   while(TRUE)
   {
      status=1;
      printf("\r\nStart typing:\r\n");
      while(!kbhit());// trong khi ky tu chua duoc nhan 
      while(status==1)
      {
          value=getc();
      if(value==99)
      {
          status=0;
          LCD_putc("\f");
          lcd_gotoxy(0,1);
          mang=" ";
          i=0;   
      }
         if(value==0)
            status=0;
         else
         {
            status=1;
            putc(value);
            LCD_putc(value);
            
         }
      }
      printf("\r\nToo slow!\r\n");
   }
}
