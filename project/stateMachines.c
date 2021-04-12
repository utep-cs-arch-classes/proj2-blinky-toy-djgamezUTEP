#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
void red_on_ctrl(){
  red_on=1;
  led_changed=1;  
}
void red_off_ctrl(){
  red_on=0;
  led_changed=1;
}
char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on==0) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void med_dim(){
  static char cntr=0;
    if(cntr%2==0){
      red_off_ctrl();

    }else{
      red_on_ctrl();
    }
  cntr+=1;
  if (cntr>100){
    cntr=0;
  }
  
}
void med_high_dim(){
  static char cntr=0;
  if(cntr>2){
    red_off_ctrl();
  }else{
    red_on_ctrl();
  }
  cntr+=1;
  if (cntr>3){
    cntr=0;
  }
}



static char dimLvl=0;
void change_dim(){
  dimLvl+=1;
  if( dimLvl>4){
    dimLvl=0;
    }
}
void dimming()
{
  static char cntr=0;
  
  switch(dimLvl){
  case 0:  red_off_ctrl();//off all the time
    break;
  case 2: med_dim();
    break;
  case 3: med_high_dim();
    break;
  case 4: red_on_ctrl();
    break;
    

  }

}
  
/*void state_advance()		/* alternate between toggling red & green 
{
  char changed = 0;
  static char subState=0;
  switch(subState){
  case 0:changed= toggle_red();
    subState+=1;
    break;
  case 1: changed= toggle_red(); susbState+=1;
   
  
  /* static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;*/
  

  //led_changed = changed;
//led_update();
//}



