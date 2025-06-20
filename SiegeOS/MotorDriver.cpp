#include "MotorDriver.h"

L293D::L293D(){
}

void L293D::begin()
{
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(DIRECTION_PIN1, OUTPUT);
  pinMode(DIRECTION_PIN2, OUTPUT);
}

void L293D::runMotor(byte direction, int enabled, byte speed) {
  if (enabled == DISABLED) {
    digitalWrite(DIRECTION_PIN1, HIGH);
    digitalWrite(DIRECTION_PIN2, HIGH);
    analogWrite(ENABLE_PIN, 0);
    return;
  }

  switch (direction) {
    case FOREWARD:
      digitalWrite(DIRECTION_PIN1, HIGH);
      digitalWrite(DIRECTION_PIN2, LOW);
      break;
    case BACKWARDS:
      digitalWrite(DIRECTION_PIN1, LOW);
      digitalWrite(DIRECTION_PIN2, HIGH);
      break;
    case BREAK:
      digitalWrite(DIRECTION_PIN1, HIGH);
      digitalWrite(DIRECTION_PIN2, HIGH);
      break;
    default:
      digitalWrite(DIRECTION_PIN1, LOW);
      digitalWrite(DIRECTION_PIN2, LOW);
      break;
  }
  analogWrite(ENABLE_PIN, speed);
}