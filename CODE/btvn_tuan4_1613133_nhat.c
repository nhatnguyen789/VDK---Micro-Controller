#include <btvn_tuan4_1613133_nhat.h>
#include<lcd.c>
#define LCD_ENABLE_PIN PIN_D0
#define LCD_RS_PIN PIN_D1
#define LCD_RW_PIN PIN_D2
#define LCD_DATA4  PIN_D4
#define LCD_DATA5  PIN_D5
#define LCD_DATA6  PIN_D6
#define LCD_DATA7  PIN_D7 


char mang1[]={"                NGUYEN TIEN NHAT                "};

void dich_trai(void);
void dich_phai(void);

void dich_trai(void)
{
    char i,j;
    while(true)
    {
        for(j=0;j<=32;j++)
        {
            for(i=1;i<=16;i++) //tuong ung 16 cot cua LCD
            {
                lcd_gotoxy(i,1);
                printf(lcd_putc,"%c",mang1[i+j-1]);  
            }   
               delay_ms(100);
         }
      }
}      
void dich_phai(void)
{
    char i,j;
    while(true)
    {
        for(j=0;j<=32;j++)
        {
            for(i=1;i<=16;i++)
            {
                lcd_gotoxy(i,1);
                printf(lcd_putc,"%c",mang1[32+i-j-1]);           
            }   
               delay_ms(100);
         }
      }
}     

void main()
{
    set_tris_D(0x00);
    lcd_init();  
    lcd_putc('\f');
    while(True)
    {
      //dich_trai();
      dich_phai();
    }
}
