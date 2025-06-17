#ifndef L293D_H
#define L293D_H

#include <Arduino.h>

#define DIRECTION_PIN1 7
#define DIRECTION_PIN2 8
#define ENABLE_PIN 9
#define SPEED 50

#define FOREWARD 0
#define BACKWARDS 1
#define BREAK 2

#define ENABLED 1
#define DISABLED -1

void initL293D();
void runMotor(byte direction, int enabled, byte speed);

#endif