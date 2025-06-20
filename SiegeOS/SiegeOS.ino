#include "MotorController.h"

MotorController motorController;

void setup() {
  motorController.begin();
}

void loop() {
  motorController.adjustAngle();
}