#include "MotorControl.h"
#include "AngleVisualizer.h"
#include "HC05.h"
#include <Arduino.h>

void setup() {
  initMotorControl();
  // initAngleVisualizer();
}

void loop() {
  // displayAngle();
  adjustAngle();
  test();
  
}