#include "AngleVisualizer.h"

void initAngleVisualizer()
{
  initLCD();
  initPotentiometer();
}

void displayAngle()
{
  printAngle(angle(INPUT), angle(OUTPUT));
}