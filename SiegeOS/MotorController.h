#ifndef MotorController_H
#define MotorController_H

#include <Arduino.h>
#include "MotorDriver.h"
#include "Potentiometer.h"
#include "BluetoothDriver.h"

class MotorController {
public:
  MotorController();
  void begin();
  void adjustAngle();

private:
  Bluetooth bluetooth;
  Potentiometer potentiometer;
  L293D L293D;
};

#endif