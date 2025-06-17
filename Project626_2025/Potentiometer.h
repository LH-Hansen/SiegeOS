#ifndef Potentiometer_H
#define Potentiometer_H

#include <Arduino.h>

#define MAX_ANGLE 240.0 //total roational angle of potentiometer
#define SAFETY_MIN 40   //angle to register from 0
#define SAFETY_MAX 190  //angle to register prior to 240
#define OUTPUT_MAX 5   //total angle range

#define INPUT  A1      //Potentiometer analog ports
#define OUTPUT A0

void initPotentiometer();
byte angle(byte pinNumber);

#endif