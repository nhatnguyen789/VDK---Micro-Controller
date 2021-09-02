#include <dong_co.h>
#fuses NOWDT,PUT,XT,NOPROTECT
#use delay(clock=20000000)
#define wire1 PIN_C0
#define wire2 PIN_C1 //chan ket noi voi module L298

#define Dir PIN_D2 //NUT NHAN DAO CHIEU
#define Up  PIN_D0 //TANG
#define Down PIN_D1 //GIAM
#define Stop PIN_D3 //Start- stop
int16 duty_cycle =512; //CAP 16
short Di=0; //chon chieu thuan hay nghich
short SS=0; //trang thai start- stop
int tocdo; //phan tram duty_cycle cua PWM

void thuan()
{
    output_high(wire1);
    output_low(wire2);
}
void nghich()
{
    output_low(wire1);
    output_high(wire2);
}
void up_down()
{
    //NUT NHAN ::: UP
    if(input(Up)==0)   //BUTTON(UP) SELECTED???
    {
        while(input(Up)==0);
        duty_cycle+=32; //tang 1 lan 32 don vi, tuong duong 100/1024=9.8% 1 lan nhan 
        set_pwm1_duty(duty_cycle); //xuat gia tri PWM
    }
    if(input(down)==0)
    {
        while(input(Down)==0);
        duty_cycle-=32;   //decrease the duty cycle 
        set_pwm1_duty(duty_cycle);
    }
}
//chuong trinh con nut dao chieu
void daochieu()
{
    if(input(Dir)==0)  //BUTTON (DIRECTION) SELECTED???
    {
        while(input(Dir)==0);
        Di=~Di; //dao bit 0 thanh 1 va nguoc lai
    }
}
//Chuong trinh con nut trang thai Start- Stop
void trangthai()
{
    if(input(Stop)==0)
    {
        while(input(Stop)==0); //hold until a button is pressed
        SS=~SS;
    }
}
//CHUONG TRINH CHINH
void main()
{
    set_tris_B(0);
    set_tris_C(0);
    set_tris_D(0x0f);
    /* PWM CONFIGURATION */
    setup_timer_2(T2_DIV_BY_1,49,1); //SET PWM FREQUENCY ~T=(49+1)*4*1/8=25(us)
    setup_ccp1(CCP_PWM);           //configuration CCP1 to PWM mode
    
    //DAT GIA TRI BAN DAU BANG = 50% (HALF SPEED)
    set_pwm1_duty(512L); //co the bo lenh nay
    
   while(TRUE)
   {
      //TODO: User Code
      trangthai();
      if(SS==1) //CHO PHEP HOAT DONG
      {
         tocdo=duty_cycle/32; //100% tuong duong 1024
         
         up_down();//goi chuong trinh nut nhan tang giam
         set_pwm1_duty(duty_cycle);
         daochieu();  //goi chuong trinh nut nhan dao chieu
         if(Di==0)
         {
             thuan();
         }
         else
         {
             nghich();
         }
       }
       else
       {
          output_low(wire1);
          output_low(wire2);
          set_pwm1_duty(0);  //xoa xung pwm 
       }
     }
}
