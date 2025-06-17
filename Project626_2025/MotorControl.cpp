#include "MotorControl.h" 

int inputBT;

void initMotorControl()
{
  initL293D();
  initPotentiometer();
  initHC05(OUTPUT_MAX);
}

void adjustAngle()
{
  if (curAngle > angle(OUTPUT))
  {
    runMotor(FOREWARD, ENABLED, SPEED);
  }
  else if (curAngle < angle(OUTPUT))
  {
    runMotor(BACKWARDS, ENABLED, SPEED);
  }
  else
  {
    runMotor(BREAK, DISABLED, SPEED);
  }
  Serial.print(curAngle);
  Serial.print("    ");
  Serial.println(angle(OUTPUT));
}