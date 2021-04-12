#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static int state_count=0;
  static char blink_count = 0;
  if (++blink_count ==350) {
    
    blink_count = 0;
    
  }
  if(++state_count==225){
    change_dim();
    
    
    state_count=0;
    
   
  }
  dimming();
  led_update();

}
