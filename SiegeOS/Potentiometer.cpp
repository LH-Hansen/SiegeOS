#include "Potentiometer.h"

Potentiometer::Potentiometer() {
}

void Potentiometer::begin() {
  Serial.begin(9600);
}

byte Potentiometer::getAngle() {
  int inputValue = analogRead(INPUT_PIN);
  float rawAngle = (inputValue / 1023.0) * MAX_ANGLE;

  rawAngle = constrain(rawAngle, SAFETY_MIN, SAFETY_MAX);

  float normalized = (rawAngle - SAFETY_MIN) / (SAFETY_MAX - SAFETY_MIN);
  float scaledAngle = normalized * OUTPUT_MAX;

  return (byte)scaledAngle;
}

byte Potentiometer::getMaxAngle() {
  return OUTPUT_MAX;
}
