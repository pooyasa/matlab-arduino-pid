
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
extern "C" void arduinoFinalCode_Outputs_wrapper(real_T *xAngle,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0] == 1)
{
    #ifndef MATLAB_MEX_FILE
/*    
        Wire.beginTransmission(MPU);
        Wire.write(0x3B);
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 6, true);
        AccX = (Wire.read() << 8 | Wire.read()) ;
        AccY = (Wire.read() << 8 | Wire.read()) ;
        AccZ = (Wire.read() << 8 | Wire.read()) ;
        RAccX = (float)AccX / 16384.0;
        RAccY = (float)AccY / 16384.0;
        RAccZ = (float)AccZ / 16384.0;        
        xAngle[0]= atan(RAccX / sqrt(RAccY *RAccY + RAccZ *RAccZ)) *180/PI;
 
 */
    
    xAngle[0] = (float)counter / 400 * 360;
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void arduinoFinalCode_Update_wrapper(real_T *xAngle,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0] != 1)
{
    #ifndef MATLAB_MEX_FILE

      pinMode(2 , INPUT_PULLUP); // Encoder A
      pinMode(3 , INPUT_PULLUP); // Encoder B
      pinMode(4 , INPUT_PULLUP); // Proximity Sensor
      pinMode(5,OUTPUT); //In1 
      pinMode(6,OUTPUT); //IN2
      pinMode(7,OUTPUT); //ENB

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
/*
      Wire.begin();                      // Initialize comunication
      Wire.setClock(400000);
      Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
      Wire.write(0x6B);                  // Talk to the register 6B
      Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
      Wire.endTransmission(true);        //end the transmission
      
  // Set Accel On 2 g
  Wire.beginTransmission(MPU);
  Wire.write(0x1C);            // sends instruction byte
  Wire.write(0b00000000);             // sends potentiometer value byte
  Wire.endTransmission();     // stop transmitting  
  // Set Sample Rate on 1kHz and 100 Hz low pass
  Wire.beginTransmission(MPU);
  Wire.write(0x1A);            // sends instruction byte
  Wire.write(0b00000100);             // sends potentiometer value byte
  Wire.endTransmission();     // stop transmitting  
  // Activate Sample Rate divider on ? ~ 255 Hz sampling Don't ask how
  Wire.beginTransmission(MPU);
  Wire.write(0x19);            // sends instruction byte
  Wire.write(0x07);             // sends potentiometer value byte
  Wire.endTransmission();     // stop transmitting  
  // Activate the Interrupt pin
  Wire.beginTransmission(MPU);
  Wire.write(0x38);            // sends instruction byte
  Wire.write(0b00000001);             // sends potentiometer value byte
  Wire.endTransmission();     // stop transmitting     
      
      for(int i = 0 ; i < 200 ; i++) {
        Wire.beginTransmission(MPU);
        Wire.write(0x3B);
        Wire.endTransmission(false);
        Wire.requestFrom(MPU, 6, true);
        AccX = (Wire.read() << 8 | Wire.read()) ;
        AccY = (Wire.read() << 8 | Wire.read()) ;
        AccZ = (Wire.read() << 8 | Wire.read()) ;
        RAccX = (float)AccX / 16384.0;
        RAccY = (float)AccY / 16384.0;
        RAccZ = (float) AccZ / 16384.0;
        // Sum all readings
        AccErrorY = AccErrorY + ((atan(-1 * (RAccX) / sqrt(pow((RAccY), 2) + pow((RAccZ), 2))) * 180 / PI));  
      }      
      AccErrorY = AccErrorY / 200;
      delay(10); 
*/ 
    #endif
    xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

