#include "iostm8s103f3.h"
#define PIN_en 1 //pA
#define PIN_rs 3 //pC

#define PIN_db7 7 //pC
#define PIN_db6 6 //pC
#define PIN_db5 5 //pC
#define PIN_db4 4 //pC


#define BIT_en  (1<<PIN_en)
#define BIT_rs  (1<<PIN_rs)
#define BIT_db7 (1<<PIN_db7)
#define BIT_db6 (1<<PIN_db6)
#define BIT_db5 (1<<PIN_db5)
#define BIT_db4 (1<<PIN_db4)

#define MASK_db (BIT_db7|BIT_db6|BIT_db5|BIT_db4)

#define N_F_code   2 //n:2-line f:5*11font
#define SC_RL_code 2 //sc:setcursor/display moving rl:right/left
#define D_C_B_code 4 //display/cursor/blinking
#define ID_SH_code 2 //cursor mov/display shift

typedef struct
{
  unsigned char Be  ;
  unsigned char Ge  ;
  unsigned char De  ;  
  unsigned char Yo  ;
  unsigned char Zhe ;
  unsigned char Ze  ;
  unsigned char II  ;
  unsigned char ii  ;
  unsigned char Le  ;
  unsigned char Pe  ;
  unsigned char Uu  ;
  unsigned char Fe  ; 
  unsigned char Ce  ;
  unsigned char Che ;
  unsigned char Sha ;
  unsigned char SCHa;
  unsigned char Tb ;
  unsigned char bI  ;
  unsigned char mb ;
  unsigned char EE  ;
  unsigned char yU  ;
  unsigned char yA  ;
  unsigned char deg ;
} cyr_eeprom_struct;


void write_wh(char rs,char db7_db4);
void write_wh_byte(char rs,char db7_db0);
void write_wh_digit(char n);
void del_tim2(char delay,char E);
void del_WH(unsigned int del);
void proba_del_tim2(void);
void init1604(void);
char print_nomber(int n, char x,char y );
void print_string(char* pointer, char x, char y); 
void clear(void);
void set_cursor(char x,char y);
char print_symb(unsigned char* ch_cyr_pointer,char x,char y,char n_CGRAM); //if LED don't provide CYR letters
void print_char(char ch, char x, char y);
char print_n_01(unsigned long int n, char x, char y ); //n=0..65535 right align x-right position
char print_n_10(unsigned int n, char x, char y ); //n=0..65535 left align x-left position
void print_n_00(unsigned long int n, char nn, char x, char y ); //n=0..65535 fixed format - nn diges x-left pos
void print_n_10_format(unsigned int n, char x, char y, char format );

void send_cyr_to_eeprom(void);
