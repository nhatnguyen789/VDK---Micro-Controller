#include <btvn_week5_1613133_nhat.h>
#include <lcd.c>
#define LCD_ENABLE_PIN PIN_D0
#define LCD_RS PIN_D1
#define LCD_RW PIN_D2
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D5
#define LCD_DATA6 PIN_D6
#define LCD_DATA7 PIN_D7

#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=Pin_C7,bits=8)
int i=0;
void main()
{
   unsigned int8 status; //
   char value;
   char mang[];
   set_tris_d(0x00);
   LCD_init();
   while(TRUE)
   {
      lcd_gotoxy(1,1);
      LCD_putc("1 + 1 = ???");
      lcd_gotoxy(1,2);
      status=1; 
      printf("\r\nNhap ket qua cua bai toan:\r\n");

      while(status==1)
      {
         value=getc();//ham nhan gia tri
         if(value == 122) //tuong ung voi chu z trong ma ascii, khi nhan z thi se xoa man hinh dong 1 cua LCD
         {
            status=0;
            LCD_putc("\f"); //lenh nay thuc hien khi nhan z,co chuc nang xoa dong 1 cua lcd va quay lai vi tri dau dong ben trai
            lcd_gotoxy(2, 1); // di den cot 2 hang so 1
            mang=""; // mang se bang khoang trang
            i=0; //i quay ve 0
         }
         if((value==0)||(value == 122))//value=0 tuong ung voi khong nhan nut gi ca, value=122 tuong ung nhan nut z 
            status=0;          // thi man hinh lcd se khong hien gi ca, con terminal thi hien thi lai dong "nhap ket qua cua bai toan
         else             //nguoc lai neu nhap bat cu ky tu nao khac z thi no se bao "sai" hoac "dung" tren lcd
         {
            status=1;         //cho phep hien thi len lcd         
            putc(value);      //nhap gia tri muon hien thi len lcd
            mang[i] = value; //luu gia tri vao mang[], chi so la i
            i++;             //i tang them mot don vi
         }
         if(value == 13)//13 trong ma ascii la ko co ky tu 
            {
               
               if ((mang[0] == 50)&&(i<3))//mang[0]=50 tuong ung voi so 2 la gia tri bai toan can tim va i =0,1,2
               {
                  status=1;
                  printf("\r\n DUNG \r\n");
                  lcd_gotoxy(12,2);//di den vi tri cot 12 dong 2 hien thi DUNG
                  LCD_putc("DUNG");// hien thi DUNG ra man hinh
                  lcd_gotoxy(1,2);  //di den vi tri cot 1 dong 2
                  lcd_putc(mang[0]); //xuat ra so 2 len man hinh lcd
                  mang=""; //con lai la khoang trang
                  i=0;    
               }
               else
               {
                  status=1;
                  printf("\r\n SAI \r\n");
                  lcd_gotoxy(1,2);
                  LCD_putc("           SAI ");
                  mang="";
                  i=0;
               }
            }
         }
         printf("\r\nEnd!\r\n");
      }
      
   }


