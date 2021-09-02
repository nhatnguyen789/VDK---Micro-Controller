#include <week_4_1613133.h>
#include<lcd.c>
#define LCD_ENABLE_PIN PIN_D0
#define LCD_RS_PIN PIN_D1
#define LCD_RW_PIN PIN_D2
#define LCD_DATA4  PIN_D4
#define LCD_DATA5  PIN_D5
#define LCD_DATA6  PIN_D6
#define LCD_DATA7  PIN_D7

void main()
{
   set_tris_D(0x00);
   lcd_init();
   lcd_putc("VAT LY TIN HOC \n \t K2021");
}
