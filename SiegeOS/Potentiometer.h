#ifndef Potentiometer_H
#define Potentiometer_H

#include <Arduino.h>

class Potentiometer {
public:
  Potentiometer();
  void begin();
  byte getAngle();
  byte getMaxAngle();

  static constexpr byte OUTPUT_MAX = 5;    // Scaled output range

private:
  // Constants for potentiometer calibration
  static constexpr byte MAX_ANGLE = 240;   // Total rotational angle of potentiometer (degrees)
  static constexpr byte SAFETY_MIN = 40;   // Minimum safe angle
  static constexpr byte SAFETY_MAX = 190;  // Maximum safe angle
  static constexpr byte INPUT_PIN = A0;    // Analog input pin for potentiometer
};

#endif