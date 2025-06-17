#ifndef MotorControl_H
#define MotorControl_H

#include <Arduino.h>

#include "L293D.h"
#include "Potentiometer.h"
#include "HC05.h"

void initMotorControl();
void adjustAngle();

#endif