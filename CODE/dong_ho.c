#include <dong_ho.h>
#use delay(clock=20000000)
#fuses HS, NOWDT, NOPROTECT,PUT, NOLVP 

#define wire1 PIN_D1
#define wire2 PIN_D2 //chan ket noi voi module L298
#define wire3 PIN_D3
#define wire4 PIN_D4 

#define read1 Pin_A0
#define read2 Pin_A1
#define read3 Pin_A2
#define read4 Pin_A3
#define read5 Pin_A5
int IN_line,In_line_last,mode;
int ss1,ss2,ss3,ss4,ss5;

void Tien()
{
    output_high(wire1);
    output_low(wire2);
    
    output_high(wire3);
    output_low(wire4);
}
void Stop()
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
void Trai()
{
   
    output_high(wire1);
    output_low(wire2);
    
    output_low(wire3);
    output_high(wire4);
}
void Phai()
{
    output_low(wire1);
    output_high(wire2);
    
    output_high(wire3);
    output_low(wire4);
}
void robotMover(int line)
{
  switch (line)
  {
    case -4:// sang trai  -----cam bien 1
    {
      Trai();
      set_pwm1_duty(150); // RC2=ENA banh phai
      set_pwm2_duty(25); // RC1=ENB banh trai
      break;
    }
    case -3://sang trai ----cam bien 1,2
    {
      Trai();
      set_pwm1_duty(100); // RC2=ENA banh phai
      set_pwm2_duty(25); // RC1=ENB banh trai
     // delay_ms(500);
      break;
    }
    case -2:// sang trai-----cam bien 2
    {
      Tien();
      set_pwm1_duty(100); // RC2=ENA banh phai
      set_pwm2_duty(50); // RC1=ENB banh trai
      //delay_ms(500);
      break;
    };
    case -1:// sang trai--------cam bien 2,3
    {
      Tien();
      set_pwm1_duty(150); // RC2=ENA banh phai
      set_pwm2_duty(100); // RC1=ENB banh trai
      //delay_ms(500);
      break;
    }
    case 0:// quay phải----------cam bien 3
    {
      Tien();
      set_pwm1_duty(150); // RC2=ENA banh phai
      set_pwm2_duty(150); // RC1=ENB banh trai
      //delay_ms(500);
      break;
    }
    case 1:// rẽ phai------------cam bien 3,4
    {
      Tien();
      set_pwm1_duty(100); // RC2=ENA banh phai
      set_pwm2_duty(150); // RC1=ENB banh trai
      //delay_ms(500);
      break;
    };
    case 2:// rẽ phai---------cam bien 4
    {
      Tien();
      set_pwm1_duty(50); // RC2=ENA banh phai
      set_pwm2_duty(100); // RC1=ENB banh trai
      //delay_ms(500);
      break;
    }
    case 3:// rẽ phai-------------cam bien 4,5
    {
      Phai();
      set_pwm1_duty(25); // RC2=ENA banh phai
      set_pwm2_duty(100); // RC1=ENB banh trai
      //delay_ms(500);
      break;
    }
    case 4:// rẽ phai------cam bien 5
    {
      Phai();
      set_pwm1_duty(25); // RC2=ENA banh phai
      set_pwm2_duty(150); // RC1=ENB banh trai
      //delay_ms(500);
      break;
    }
    case 5:// rẽ phải
    {
      if(mode==0)           //mode=0 trai
      {
      Trai();
      set_pwm1_duty(80); // RC2=ENA banh phai
      set_pwm2_duty(0); // RC1=ENB banh trai
      //delay_ms(500);
      }
      else              //mode=1 phai
      {
      Phai();
      set_pwm1_duty(0); // RC2=ENA banh phai
      set_pwm2_duty(80); // RC1=ENB banh trai
      //delay_ms(500);
      }
      break;
    }
    case 6:
    {
      Trai();
      set_pwm1_duty(80); // RC2=ENA banh phai
      set_pwm2_duty(0); // RC1=ENB banh trai
     // delay_ms(500);
      break;
    }
    case 7:
    {
      Phai();
      set_pwm1_duty(0); // RC2=ENA banh phai
      set_pwm2_duty(80); // RC1=ENB banh trai
     // delay_ms(500);
      break;
    }
    
  }
} 
int In_SenSor()
{
  ss1 = input(Pin_A0);
  ss2 = input(Pin_A1);
  ss3 = input(Pin_A2);
  ss4 = input(Pin_A3);
  ss5 = input(Pin_A5);
  
  if((ss1==1)&&(ss2==1)&&(ss3==0)&&(ss4==1)&&(ss5==1))//giua line 11011 // led : 3
  {
    return 0; 
  }
  else if((ss1==1)&&(ss2==1)&&(ss3==0)&&(ss4==0)&&(ss5==1))//lech trai cap 1, led 3/4
  {
    mode=1;
    return 1;
  }
  else if((ss1==1)&&(ss2==1)&&(ss3==1)&&(ss4==0)&&(ss5==1))//lech trai cap 2/ led:4
  {
    mode=1;
    return 2;
  }
  else if((ss1==1)&&(ss2==1)&&(ss3==1)&&(ss4==0)&&(ss5==0))//lech trai cap 3/ led 4,5
  {
    mode=1;
    return 3;
  }
  else if((ss1==1)&&(ss2==1)&&(ss3==1)&&(ss4==1)&&(ss5==0))//lech trai cap 4/  led :5
  {
    mode=1;
    return 4;
  }
  else if((ss1==1)&&(ss2==0)&&(ss3==0)&&(ss4==1)&&(ss5==1))//lech phai cap 1 / LED: 2,3
  {
    mode=0;
    return -1;
  }
  else if((ss1==1)&&(ss2==0)&&(ss3==1)&&(ss4==1)&&(ss5==1))//lech phai cap 2 / LED: 2
  {
    mode=0;
    return -2;
  }
  else if((ss1==0)&&(ss2==0)&&(ss3==1)&&(ss4==1)&&(ss5==1))//lech phai cap 3  / LED : 2, 1
  {
    mode=0;
    return -3;
  }
  else if((ss1==0)&&(ss2==1)&&(ss3==1)&&(ss4==1)&&(ss5==1))//lech phai cap 4  / LED : 1
  {
    mode=0;
    return -4;
  }
  else if((ss1==1)&&(ss2==1)&&(ss3==1)&&(ss4==1)&&(ss5==1))//lech hoàn toàn //KHONG NAM TRONG LED NAO CA
  {
    return 5;
  }
  else if((ss1==0)&&(ss2==0)&&(ss3==0)&&(ss5==1))//góc vuong sang trai// LED:1,2,3
  {
    mode=0;
    return 6;
  }
  else if((ss1==1)&&(ss3==0)&&(ss4==0)&&(ss5==0))//góc vuong sang phai// LED : 3,4,5
  {
    mode=1;
    return 7;
  }
}


void main()
{
   setup_timer_2(T2_DIV_BY_16,255,1);
   setup_ccp1(CCP_PWM); //RC2=ENA
   setup_ccp2(CCP_PWM); //RC1=ENB
   set_tris_B(0xFF);
   while(TRUE)
   {      
    if(input_state(PIN_B0)==1)
    {
        In_line_last = IN_line;
        IN_line = In_SenSor();
        if(IN_line!=In_line_last)
        {
              if(In_line_last!=5)
              {
               robotMover(IN_line);
              } 
        }
     }
     else if(input_state(PIN_B1)==1)
     {
         Tien();
         set_pwm1_duty(150); // RC2=ENA banh phai
         set_pwm2_duty(150); // RC1=ENB banh trai
     }
     else if(input_state(PIN_B2)==1)
     {
         Lui();
         set_pwm1_duty(150); // RC2=ENA banh phai
         set_pwm2_duty(150); // RC1=ENB banh trai
     }
     else if(input_state(PIN_B3)==1)
     {
         Trai();
         set_pwm1_duty(100); // RC2=ENA banh phai
         set_pwm2_duty(50); // RC1=ENB banh trai
     }
     else if(input_state(PIN_B4)==1)
     {
         Phai();
         set_pwm1_duty(50); // RC2=ENA banh phai
         set_pwm2_duty(100); // RC1=ENB banh trai
     }
     else if(input_state(PIN_B5)==1)
     {
         Stop();
         set_pwm1_duty(0); // RC2=ENA banh phai
         set_pwm2_duty(0); // RC1=ENB banh trai
     }
     else 
     {
         Stop();
     }
    }
}
