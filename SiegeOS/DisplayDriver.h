#ifndef DisplayDriver_H
#define DisplayDriver_H

#include <LiquidCrystal.h>
#include <Arduino.h>

class CrystalDisplay {
public:
  CrystalDisplay();
  void begin();
  void printAngle(byte inputAngle, byte outputAngle);

  private:
  void displayLine(byte row, const __FlashStringHelper* label, byte angle);
};

#endif