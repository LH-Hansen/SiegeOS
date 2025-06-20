#include "MotorController.h"

MotorController::MotorController() {}

void MotorController::begin()
{
  potentiometer.begin();
  bluetooth.begin(potentiometer.getMaxAngle()); 
  motorDriver.begin();
}

void MotorController::adjustAngle()
{
  bluetooth.listenForCommands();

  byte curAngle = bluetooth.getAngle();
  byte motorAngle = potentiometer.getAngle();

  if (curAngle > motorAngle) {
    motorDriver.runMotor(motorDriver.Forward(), motorDriver.Enabled(), motorDriver.getDefaultSpeed());
  }
  else if (curAngle < motorAngle) {
    motorDriver.runMotor(motorDriver.Backward(), motorDriver.Enabled(), motorDriver.getDefaultSpeed());
  }
  else {
    motorDriver.runMotor(motorDriver.Stop(), motorDriver.Disabled(), motorDriver.getDefaultSpeed());
  }
}
