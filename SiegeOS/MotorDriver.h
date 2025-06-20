#ifndef MotorDriver_H
#define MotorDriver_H

#include <Arduino.h>

class L293D{
  public:
    L293D();
    void begin();
    void runMotor(byte direction, int enabled, byte speed);

    static constexpr byte getDefaultSpeed() { return SPEED; }

    static constexpr byte Forward()  { return FOREWARD; }
    static constexpr byte Backward() { return BACKWARDS; }
    static constexpr byte Stop()     { return BREAK; }

    static constexpr int Enabled()   { return ENABLED; }
    static constexpr int Disabled()  { return DISABLED; }

  private:
    // H-Bridge connections
    static constexpr byte DIRECTION_PIN1 = 7; 
    static constexpr byte DIRECTION_PIN2 = 8;
    static constexpr byte ENABLE_PIN     = 9;
    static constexpr byte SPEED          = 50;

    // Motor direction
    static constexpr byte FOREWARD       = 0;
    static constexpr byte BACKWARDS      = 1;
    static constexpr byte BREAK          = 2;

    // Motor state
    static constexpr int  ENABLED        = 1;
    static constexpr int  DISABLED       = -1;
};

#endif