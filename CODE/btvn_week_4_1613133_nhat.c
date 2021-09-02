#include <btvn_week_4_1613133_nhat.h>

#include <lcd.c>
#define LCD_ENABLE_PIN  PIN_D0;
#define LCD_RS PIN_D1;
#define LCD_RW PIN_D2;
#define LCD_DATA4 PIN_D4;
#define LCD_DATA5 PIN_D5;
#define LCD_DATA6 PIN_D6;
#define LCD_DATA7 PIN_D7;
int count=0;
int i=1;
#int_TIMER0
void ngat_timer0()
{

    
   count++;
  
   if(count==10)
   {
      lcd_gotoxy(i, 1); 
      LCD_putc("NGUYEN TIEN NHAT                 NGUYEN TIEN NHAT                 ");
      lcd_gotoxy(i, 2); 
      LCD_putc("1613133       1613133       ");
      if(i==-16)
      {
         i = 1;
      }
      i--;
      
      count=0;
   }
   set_timer0(15536);
}
void main()
{
   set_tris_d(0x00);
   LCD_init();
   set_tris_b(0x00);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8);
   set_timer0(15536);
   while(TRUE)
   {
      //TODO: User Code
   }

}
