#include <Final_Exam.h>
#FUSES hs
#use delay(clock = 20000000)
#define LED PIN_C4

#define Stop PIN_A0
#define Run PIN_A1
#define Edit_gio PIN_A2
#define Edit_phut PIN_A3

unsigned int8 ma7doan[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
signed int32 gio, phut, giay, i;


void hienthi()
{
    output_D(ma7doan[phut/10]);     output_low(PIN_C3);      delay_ms(1);      output_high(PIN_C3); //hien thi hang chuc cua phut  //dua tin hieu Pin_c3 xuong muc 0 //dua tin hieu pin_c3 len muc 1
    output_D(ma7doan[phut%10]);     output_low(PIN_C2);      delay_ms(1);      output_high(PIN_C2); //hien thi hang don vi cua phut
    output_D(ma7doan[giay/10]);     output_low(PIN_C1);      delay_ms(1);      output_high(PIN_C1); //hien thi hang chuc cua giay
    output_D(ma7doan[giay%10]);     output_low(PIN_C0);      delay_ms(1);      output_high(PIN_C0); //hien thi hang don vi cua giay
    
    output_D(ma7doan[gio/10]);      output_low(PIN_C5);      delay_ms(1);      output_high(PIN_C5);
    output_D(ma7doan[gio%10]);      output_low(PIN_C6);      delay_ms(1);      output_high(PIN_C6);
}
void nhap_nhay()
{
    output_high(LED);
    for(i = 0; i < 125; i++)
    {
        hienthi();
    }
    output_low(LED);
    for(i = 0; i < 125; i++)
    {
        hienthi();
    }
}

void main()
{
   set_tris_A(0x01);
   set_tris_C(0x00);
   set_tris_D(0x00);
   
   gio = 0;
   
   giay = 0;
   phut = 0;
   
   while(TRUE)
   {
     // giay++;
     // nhap_nhay();
      //if(giay > 59)
      //{
        //  giay = 0;
          //phut++;
          //if(phut > 59)
          //{
            //  gio++;
              //phut = 0;
              //giay = 0;
              //if(gio > 23)
              //{
                //  gio = 0;
                  //phut = 0;
                  //giay = 0;
              //}
          //}
       //}
       for(;gio < 24; gio++)
       {
          for(;phut < 60; phut++)
          {
              for(;giay < 60; giay++)
              {
                  nhap_nhay();
                  
        if(!input(Stop))
        {
            while(true)
           {
                if(!input(Edit_gio))
                {
                    gio = (++gio)%24;
                    delay_ms(200);
                    //if(gio == 0) gio = 24;
                    while(!input(Edit_gio)) nhap_nhay();
                }
                if(!input(Edit_phut))
                {
                    phut = (++phut)%60;
                    delay_ms(200);
                    while(!input(Edit_phut)) nhap_nhay();
                }
                if(!input(Run))
                {
                   break;
                }
                nhap_nhay();
            while(!input(Stop));
           }
        }
    }
    giay = 0;
    }
    phut = 0;
    }
    gio = 0;
    }
}
