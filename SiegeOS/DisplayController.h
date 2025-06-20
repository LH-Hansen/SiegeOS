#ifndef DisplayController_H
#define DisplayController_H

#include <Arduino.h>
#include "DisplayDriver.h"
#include "Potentiometer.h"
#include "BluetoothDriver.h"

class DisplayController {
public:
  DisplayController();
  void begin();
  void displayAngle();

private:
  Bluetooth bluetooth;
  Potentiometer potentiometer;
  CrystalDisplay crystalDisplay;
};

#endif