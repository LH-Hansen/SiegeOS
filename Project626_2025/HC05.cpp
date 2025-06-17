#include "HC05.h"

byte curAngle = 0;  //defualt position
byte maxAngle;

const byte BUFFER_SIZE = 32;
char inputBuffer[BUFFER_SIZE];
byte bufferIndex = 0;

void initHC05(byte outputMax) {
  maxAngle = outputMax;
  curAngle = maxAngle / 2;

  pinMode(3, HIGH);
  Serial.begin(9600);
  Serial.println("Ready for commands...");
}

void handleCommand(char* cmd) {
  Serial.print("Received command: ");
  Serial.println(cmd);

  if (strcmp(cmd, "FIRE") == 0) {
    Serial.println("-> Firing!");

  } else if (strcmp(cmd, "WINDUP") == 0) {
    Serial.println("-> Winding up...");

  } else if (strncmp(cmd, "ANGLE ", 6) == 0) {
    curAngle = atoi(cmd + 6);  // Get the number after "ANGLE "

    if (curAngle < 0 || curAngle > maxAngle) {
      Serial.print("-> Angle out of bounds: ");
      curAngle = maxAngle / 2;

    } else {
      Serial.print("-> Set angle to: ");
      Serial.println(curAngle);
    }

  } else {
    Serial.println("-> Unknown command");
  }
}

int test() {
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n') {
      inputBuffer[bufferIndex] = '\0';  // Null-terminate the string

      // Handle the command
      handleCommand(inputBuffer);

      // Reset buffer for next message
      bufferIndex = 0;
    } else if (c != '\r') {
      if (bufferIndex < BUFFER_SIZE - 1) {
        inputBuffer[bufferIndex++] = c;
      } else {
        bufferIndex = 0;  // Reset on overflow
        Serial.println("Error: input too long");
      }
    }
  }
}
