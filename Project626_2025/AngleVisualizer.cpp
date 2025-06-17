#include "AngleVisualizer.h"

void initAngleVisualizer()
{
  initLCD();
  initHC05();
  initPotentiometer();
}

void displayAngle()
{
  printAngle(curAngle, angle(OUTPUT));
}