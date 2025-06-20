#ifndef BluetoothDriver_H
#define BluetoothDriver_H

#include <Arduino.h>

#include <ArduinoBLE.h>

class Bluetooth {
public:
  Bluetooth();

  void begin(byte maxAngle);
  void listenForCommands();

  int getAngle() const {
    return curAngle;
  }

private:
  void handleCommand(const String& cmd);

  byte maxAngle;
  byte curAngle;

  BLEService* commandService;
  BLEStringCharacteristic* requestCharacteristic;
  BLEStringCharacteristic* responseCharacteristic;

};

#endif
