#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal.h>
#include <Arduino.h>
#include "Potentiometer.h"

void initLCD();
void printAngle(byte inputAngle, byte outputAngle);

#endif