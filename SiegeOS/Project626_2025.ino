#include "MotorControl.h"
#include "AngleVisualizer.h"
#include <Arduino.h>

void setup() {
  initMotorControl();
  initAngleVisualizer();
}

void loop() {
  displayAngle();
  adjustAngle();
}