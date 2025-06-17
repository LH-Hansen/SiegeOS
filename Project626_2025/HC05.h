#ifndef HC05_H
#define HC05_H

#include <Arduino.h>
#include <SoftwareSerial.h>

extern byte curAngle;

void initHC05(byte outpuMax);
int test();

#endif
