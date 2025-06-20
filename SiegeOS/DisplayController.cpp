#include "DisplayController.h"

DisplayController::DisplayController(){
}

void DisplayController::begin()
{
  crystalDisplay.begin();
  potentiometer.begin();
  bluetooth.begin(potentiometer.getMaxAngle());
}

void DisplayController::displayAngle()
{
  bluetooth.listenForCommands();

  crystalDisplay.printAngle(bluetooth.getAngle(), potentiometer.getAngle());
}