
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
#define MPU 0x68
#define Arduino 100
#include <Arduino.h>
/*#include "includes/Wire.h"
#include "includes/Wire.cpp"
#include "includes/utility/twi.h"
#include "includes/utility/twi.c"
float RAccX,RAccY,RAccZ;
int16_t AccX,AccY,AccZ;
float AccErrorY;
*/
int eeAddress = 0;   //Location we want the data to be put.
int readstate = 0;   //Variable to store data read from EEPROM.
int32_t counter = 0;
int16_t perCycle = 400;
#include "includes/myLib.h"
#include "includes/myLib.cpp"

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void arduinoFinalCode_Outputs_wrapper(real_T *xAngle,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0] == 1)
{
    #ifndef MATLAB_MEX_FILE   
    xAngle[0] = (float)counter / 400 * 360;
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void arduinoFinalCode_Update_wrapper(real_T *xAngle,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0] != 1)
{
    #ifndef MATLAB_MEX_FILE
      pinMode(2 , INPUT_PULLUP); // Encoder A
      pinMode(3 , INPUT_PULLUP); // Encoder B
      pinMode(4 , INPUT_PULLUP); // Proximity Sensor
      pinMode(5 , OUTPUT); //In1 
      pinMode(6 , OUTPUT); //IN2
      pinMode(7 , OUTPUT); //ENB

      while(digitalRead(4))
       {
        digitalWrite(5,1);
        digitalWrite(6,0);
        analogWrite(7,255);
       }
      counter = 0;
      digitalWrite(5,0);
      digitalWrite(6,0);
      analogWrite(7,0);      
      attachInterrupt(digitalPinToInterrupt(2) ,interCounter1 ,CHANGE);
      attachInterrupt(digitalPinToInterrupt(3) ,interCounter2 ,CHANGE);
    #endif
    xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

