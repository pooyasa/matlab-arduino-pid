#include "myLib.h"

void interCounter1(){
  if (digitalRead(2))
    {
      if(digitalRead(3))
        counter ++;
      else
        counter --;
    }
  else 
    {
      if(digitalRead(3))
        counter --;
      else
        counter ++;
    }
}

void interCounter2(){
  if (digitalRead(3))
    {
      if(digitalRead(2))
        counter --;
      else
        counter ++;
    }
  else 
    {
      if(digitalRead(2))
        counter ++;
      else
        counter --;
    }  
}
/*void stateUpdate(){
    EEPROM.get(eeAddress, readstate);
    EEPROM.put(eeAddress, !readstate);
}*/