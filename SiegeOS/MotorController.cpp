#include "MotorController.h"

MotorController::MotorController() {}

void MotorController::begin()
{
  potentiometer.begin();
  bluetooth.begin(potentiometer.getMaxAngle()); 
  L293D.begin();
}

void MotorController::adjustAngle()
{
  bluetooth.listenForCommands();

  byte curAngle = bluetooth.getAngle();
  byte motorAngle = potentiometer.getAngle();

  if (curAngle > motorAngle) {
    L293D.runMotor(L293D::Forward(), L293D::Enabled(), L293D::getDefaultSpeed());
  }
  else if (curAngle < motorAngle) {
    L293D.runMotor(L293D::Backward(), L293D::Enabled(), L293D::getDefaultSpeed());
  }
  else {
    L293D.runMotor(L293D::Stop(), L293D::Disabled(), L293D::getDefaultSpeed());
  }

  // Serial.print(curAngle);
  // Serial.print("  ");
  // Serial.println(motorAngle);
}
