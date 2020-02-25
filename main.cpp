#include "iostm8s103f3.h"
#include "measurement.h"
#include "wh1604a.h"

sensor_struct s_sensor;
cyr_eeprom_struct s_cyr_eeprom[8] @0x4010; //store setting variables (in EEPROM)()

int main()
{
char n_c=0; //for cgram_wh1602  

init1604();
init_ADC_3456();
//send_cyr_to_eeprom();
/////////////////////////////////////////////////////////////////////////////
////////////print splash screen/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
write_wh_byte(1,'T');
n_c=print_symb(&s_cyr_eeprom[0].II,2,1,n_c);
print_string("MO",3,1);
n_c=print_symb(&s_cyr_eeprom[0].Fe,5,1,n_c);
write_wh_byte(1,'E');
n_c=print_symb(&s_cyr_eeprom[0].ii,7,1,n_c);
print_string("MAKAP",1,2);
n_c=print_symb(&s_cyr_eeprom[0].mb,6,2,n_c);
print_string("EB",7,2);
sys_del_mes(2000);//del=1ms
clear();
/////////////////////////////////////////////////////////////////////////////

 while(1)
 { 

s_sensor.t_3=get_temp(5);
s_sensor.t_4=get_temp(6);
s_sensor.t_1=get_temp(3);
s_sensor.t_2=get_temp(4);
print_n_10_format(s_sensor.t_1,1,1,3);
sys_del_mes(200);//del=1ms
if((s_sensor.t_1>lim_t4)||(s_sensor.t_2>lim_t4)||(s_sensor.t_3>lim_t4)||(s_sensor.t_3>lim_t4)||(s_sensor.t_4>lim_t4)) saund_del_mes(200);
else
 if((s_sensor.t_1>lim_t3)||(s_sensor.t_2>lim_t3)||(s_sensor.t_3>lim_t3)||(s_sensor.t_3>lim_t3)||(s_sensor.t_4>lim_t3)) saund_del_mes(100);
  else
   if((s_sensor.t_1>lim_t2)||(s_sensor.t_2>lim_t2)||(s_sensor.t_3>lim_t2)||(s_sensor.t_3>lim_t2)||(s_sensor.t_4>lim_t2)) saund_del_mes(50);
    else
     if((s_sensor.t_1>lim_t1)||(s_sensor.t_2>lim_t1)||(s_sensor.t_3>lim_t1)||(s_sensor.t_3>lim_t1)||(s_sensor.t_4>lim_t1)) saund_del_mes(20);

print_n_10_format(s_sensor.t_2,6,1,3);
sys_del_mes(200);//del=1ms

print_n_10_format(s_sensor.t_3,1,2,3);
sys_del_mes(200);//del=1ms

print_n_10_format(s_sensor.t_4,6,2,3);
sys_del_mes(200);//del=1ms

 }
}
