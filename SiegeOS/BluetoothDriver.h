#ifndef BluetoothDriver_H
#define BluetoothDriver_H

#include <Arduino.h>

class Bluetooth {
  public:
    Bluetooth();                //Constructor

    void begin(byte outputMax);  
    void listenForCommands();   

    byte getAngle();              

  private:
    static const byte BUFFER_SIZE = 32;
    char inputBuffer[BUFFER_SIZE];
    byte bufferIndex = 0;

    byte maxAngle;
    byte curAngle = 0;

    void handleCommand(char* cmd);
};

#endif
