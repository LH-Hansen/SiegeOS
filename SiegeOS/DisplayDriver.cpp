#include "DisplayDriver.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

CrystalDisplay::CrystalDisplay(){
}

void CrystalDisplay::begin() {
  lcd.begin(16, 2);
}

void CrystalDisplay::displayLine(byte row, const __FlashStringHelper* label, byte angle)
{
  lcd.setCursor(0, row);
  lcd.print(label);
  lcd.print(angle);
  lcd.write(byte(223));
  lcd.print(F("    "));
}

void CrystalDisplay::printAngle(byte inputAngle, byte outputAngle) {
  displayLine(0, F("Input:  "), inputAngle);
  displayLine(1, F("Output: "), outputAngle);
}