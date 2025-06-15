#include "Potentiometer.h"

void initPotentiometer()
{
  Serial.begin(9600);
}

byte rawAngle(byte pinNumber)
{
  int inputValue = analogRead(pinNumber);
  return (inputValue / 1023.0) * MAX_ANGLE;
}

byte angle(byte pinNumber)
{
  int inputValue = analogRead(pinNumber);
  float rawAngle = (inputValue / 1023.0) * MAX_ANGLE;

  rawAngle = constrain(rawAngle, SAFETY_MIN, SAFETY_MAX);

  float normalized = (rawAngle - SAFETY_MIN) / (SAFETY_MAX - SAFETY_MIN);
  float scaledAngle = normalized * OUTPUT_MAX;

  return (byte)scaledAngle;
}