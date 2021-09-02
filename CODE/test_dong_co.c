#include <test_dong_co.h>
#use delay(clock=20000000)
#fuses HS, NOWDT, NOPROTECT,PUT, NOLVP 
#INT_AD
//NOWDT:ko su dung chuc nang watch dog timers
//NOLVP:lap trinh dien ap thap
//Put:su dung bo dinh thoi khi co nguon de keo dai them thoi gian reset vdk de cho nguon on dinh, thoi gian keo dai them 72ms
//NOPROTECT:khong su dung bao ve ma code nap vao bo nho flash ben trong
//HS:su dung bo dao dong tan so cao 4MHz den 20Mhz
//XT:su dung cho thach anh <4Mhz
//BROWNOUT: dat lai khi phat hien brownout
#define wire1 PIN_D1
#define wire2 PIN_D2 //chan ket noi voi module L298
#define wire3 PIN_D3
#define wire4 PIN_D4 

//int16 value1,value2,value3,value4,value5;
//#INT_CCP1 //Capture or Compare on unit 1 
//#INT_CCP2 //Capture or Compare on unit 2 
//#define Dir PIN_D2 //NUT NHAN DAO CHIEU
//short Di=0; //chon chieu thuan hay nghich

//vach= den=0 (dung)
//vach= trang=1
void Tien()
{
    output_high(wire1);
    output_low(wire2);
    
    output_high(wire3);
    output_low(wire4);
}
void stop()
{
    output_low(wire1);
    output_low(wire2);
    
    output_low(wire3);
    output_low(wire4);
}
void Lui()
{
    output_low(wire1);
    output_high(wire2);
    
    output_low(wire3);
    output_high(wire4);
}
void trai()
{
   
    output_high(wire1);
    output_low(wire2);
    
    output_low(wire3);
    output_high(wire4);
}
void phai()
{
    output_low(wire1);
    output_high(wire2);
    
    output_high(wire3);
    output_low(wire4);
}
 
/*void daochieu()
{
    if(input(Dir)==0)  //BUTTON (DIRECTION) SELECTED???
    {
        while(input(Dir)==0);
        Di=~Di; //dao bit 0 thanh 1 va nguoc lai
    }
}*/
void AD_Init() //initialize A/D converter 
{
setup_adc_ports(A_ANALOG); //set analog input ports: A0,A1,A3,A5, 
setup_adc(ADC_CLOCK_INTERNAL); //using internal clock 
}
int lechvach5mat(int x)
{
  /*
      Âm là lệch phải
      Dương là lệch trái
      Mức �'ộ lệch giảm tăng dần : 1 3 2
  */ 
     int value1,value2,value3,value4,value5;
     AD_Init();
     set_adc_channel(0); //input Analog at pin A0 
     delay_us(10);
     value1 = read_ADC();

     set_adc_channel(1); //input Analog at pin A1 
     delay_us(10);
     value2 =read_ADC();

     set_adc_channel(2); //input Analog at pin A2 
     delay_us(10);
     value3 =read_ADC();

     set_adc_channel(3); //input Analog at pin A3 
     delay_us(10);
     value4 =read_ADC();

     set_adc_channel(4); //input Analog at pin A5 
     delay_us(10);
     value5 = read_ADC();

     delay_us(10); //sample hold time 
     int lechvach = -2 * value1 - value2 + value4 + 2 * value5;
  switch (lechvach)
  {
    case -3:// cái này là do 2 mắt biên �'ều chạm vạch
    {
      return x=-2;
      break;
    }
    case -2:
    {
      return x=-3;
      break;
    }
    case -1:
    {
      return x=-1;
      break;
    }
    case 0:
    {
      return x=0;
      break;
    }
    case 1:
    {
      return x=1;
      break;
    }
    case 2:
    {
      return x=3;
      break;
    }
    case 3:
    {
      return x=2;
      break;
    }
  }
}
int trangThai5CamBien(int y)
{
  /*
      Âm là lệch phải
      Dương là lệch trái
      Mức �'ộ lệch giảm tăng dần : 1 2 3
  */ 
     int value1,value2,value3,value4,value5;
     AD_Init();
     set_adc_channel(0); //input Analog at pin A0 
     delay_us(10);
     value1 = read_ADC();

     set_adc_channel(1); //input Analog at pin A1 
     delay_us(10);
     value2 =read_ADC();

     set_adc_channel(2); //input Analog at pin A2 
     delay_us(10);
     value3 =read_ADC();

     set_adc_channel(3); //input Analog at pin A3 
     delay_us(10);
     value4 =read_ADC();

     set_adc_channel(4); //input Analog at pin A5 
     delay_us(10);
     value5 = read_ADC();

     delay_us(10); //sample hold time 
     int x;
     int tt=lechvach5mat(x);
  switch (tt)
  {
    case -3:
    {
      return y=-3;
      break;
    }
    case -2:
    {
      return y=-2;
      break;
    }
    case -1:
    {
      return y=-1;
      break;
    }
    case 0:
    {
      if ( (abs(value1) + abs(value2) + abs(value3) + abs(value4) + abs(value5)) == 0)
      {
        return y=200;
      }
      else
      {
        return y=0;
      }
      break;
    }
    case 1:
    {
      return y=1;
      break;
    }
    case 2:
    {
      return y=2;
      break;
    }
    case 3:
    {
      return y=3;
      break;
    }
   } 
}

void do_line(int dt)
{
  int y;
  dt=trangThai5CamBien(y);
  switch(dt)
  {
    case 0:
    {
      Tien();
      set_pwm1_duty(192); // RC2=ENA 
      set_pwm2_duty(192); // RC1=ENB set 75%
      delay_ms(2000);
      break;
     }
    case 1:
    {
      Tien();
      set_pwm1_duty(152); // RC2=ENA 
      set_pwm2_duty(192); // RC1=ENB set 75%
      delay_ms(2000);
      break;
     }
    case 2:
    {
      Tien();
      set_pwm1_duty(112); // RC2=ENA 
      set_pwm2_duty(192); // RC1=ENB set 75%
      delay_ms(2000);
      break;
    }
    case 3:
    {
      Tien();
      set_pwm1_duty(0); // RC2=ENA 
      set_pwm2_duty(192); // RC1=ENB set 75%
      delay_ms(2000);
      break;
    }
    case -1:
    {
      Tien();
      set_pwm1_duty(192); // RC2=ENA 
      set_pwm2_duty(152); // RC1=ENB set 75%
      delay_ms(2000);
      break;
    }
    case -2:
    {
      Tien();
      set_pwm1_duty(192); // RC2=ENA 
      set_pwm2_duty(112); // RC1=ENB set 75%
      delay_ms(2000);
      break;
    }
    case -3:
    {
      Tien();
      set_pwm1_duty(192); // RC2=ENA 
      set_pwm2_duty(0); // RC1=ENB set 75%
      delay_ms(2000);
      break;
    }
    case 200:
    {
      //Tien(SpMaxL,SpMaxR-150);
      Lui();
      set_pwm1_duty(50); // RC2=ENA 
      set_pwm2_duty(50); // RC1=ENB 
      delay_ms(2000);
      //Rephai();
      break;
    }
    default:
    {
        stop();
    }break;
  }
}

void main()
{
   int dt;
   AD_Init();
   setup_timer_2(T2_DIV_BY_16,255,1);
   setup_ccp1(CCP_PWM);
   setup_ccp2(CCP_PWM);
   set_tris_D(0x00);
   //set_tris_A(0x00);
   while(TRUE)
   {
       do_line(dt);
   }
}




