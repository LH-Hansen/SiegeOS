#include "MotorControl.h" 

void initMotorControl()
{
  initL293D();
  initPotentiometer();
}

void adjustAngle()
{
  if (angle(INPUT) > angle(OUTPUT))
  {
    runMotor(FOREWARD, ENABLED, SPEED);
  }
  else if (angle(INPUT) < angle(OUTPUT))
  {
    runMotor(BACKWARDS, ENABLED, SPEED);
  }
  else
  {
    runMotor(BREAK, DISABLED, SPEED);
  }
  Serial.print(angle(INPUT));
  Serial.print("    ");
  Serial.println(angle(OUTPUT));
}