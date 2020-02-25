
#define PIN_ADC_chanal_3     2  //port D(ch#3)
#define BIT_ADC_chanal_3    (1<<PIN_ADC_chanal_3 )
#define PIN_ADC_chanal_4     3  //port D(ch#4)
#define BIT_ADC_chanal_4    (1<<PIN_ADC_chanal_4 )
#define PIN_ADC_chanal_5     5  //port D(ch#5)
#define BIT_ADC_chanal_5    (1<<PIN_ADC_chanal_5 )
#define PIN_ADC_chanal_6     6  //port D(ch#6)
#define BIT_ADC_chanal_6    (1<<PIN_ADC_chanal_6 )
#define BIT_MASK_ch3456      (BIT_ADC_chanal_3|BIT_ADC_chanal_4|BIT_ADC_chanal_5|BIT_ADC_chanal_6)

#define PIN_SAUND     5  //port B
#define BIT_SAUND    (1<<PIN_SAUND  )

#define lim_t1 50
#define lim_t2 100
#define lim_t3 150
#define lim_t4 200

typedef struct
{
 unsigned int t_1  ;
 unsigned int t_2  ;
 unsigned int t_3  ;
 unsigned int t_4  ; 
} sensor_struct;

void sys_del_mes(unsigned int del);
void saund_del_mes(unsigned int del);//del=1ms
void init_ADC_3456(void);
unsigned int get_ADC(char ch);
unsigned int resistance_calculation ( unsigned int r_value, unsigned int value_ADC);
unsigned int get_temp(char ch);

void write_eeprom(char* addr_eeprom,char data);///save to eeprom
