#include "iostm8s103f3.h"
#include "measurement.h"
#include "wh1604a.h"

void sys_del_mes(unsigned int del)//del=1ms
{ 
 
  for(unsigned int i=0;i<del;i++)
  {
    for(char j=0;j<150;j++){asm("nop");}
    for(char j=0;j<180;j++){asm("nop");}
  }
  asm("nop");
}

void saund_del_mes(unsigned int del)//del=1ms
{ 
  PB_DDR|=BIT_SAUND;
  for(unsigned int i=0;i<del;i++)
  { 
    PB_DDR|=BIT_SAUND;
    for(char j=0;j<150;j++){asm("nop");}
    for(char j=0;j<180;j++){asm("nop");}
    PB_DDR&=~BIT_SAUND;
  }
  PB_DDR&=~BIT_SAUND;
}

void init_ADC_3456(void)
{
  PD_DDR&=~BIT_MASK_ch3456 ;
  PD_CR1&=~BIT_MASK_ch3456 ;
  PD_CR2&=~BIT_MASK_ch3456 ;
  ADC_CR1_CONT=0;
  //ADC_CSR_CH=4;
  //ADC_CR2_ALIGN=1;
  //ADC_CR1_ADON=1;  
}
 
unsigned int get_ADC(char ch)
{

char h=0;
char l=0;
  ADC_CSR_CH=ch;
  ADC_CR1_ADON=1; 
  ADC_CR1_ADON=1; //dubble 'ADON" for switch on ADC
while(ADC_CSR_EOC==0)
  {asm("nop");}

ADC_CSR_EOC=0;
h=ADC_DRH;
l=ADC_DRL;
return ((h<<2)|l); 
}


unsigned int resistance_calculation ( unsigned int r_value, unsigned int value_ADC)
{
  return(((unsigned long int)r_value*value_ADC)/(1024-value_ADC));
}

unsigned int get_temp(char ch)
{
unsigned long int r;
unsigned long int t;
unsigned int adc;
adc=get_ADC(ch);
r = resistance_calculation(1500,adc);  //r=xxxx -> xxx.x Ohm R=150.0 Ohm
t=(unsigned long int)97*r*r+(unsigned long int)2325000*r-(unsigned long int)2422000000;
t=t/10000000;
return t;
}


void write_eeprom(char* addr_eeprom,char data)///save to eeprom
{ asm("sim");
  	if (!((FLASH_IAPSR) & (MASK_FLASH_IAPSR_DUL)))
    {  // unlock EEPROM
       FLASH_DUKR = 0xAE;
       FLASH_DUKR = 0x56;
    }
  asm("rim");
       while (!((FLASH_IAPSR) & (MASK_FLASH_IAPSR_DUL))) {;}
       *addr_eeprom=data;
       FLASH_IAPSR &= ~(MASK_FLASH_IAPSR_DUL); // lock EEPROM
}





