#include "BluetoothDriver.h"

Bluetooth::Bluetooth() {
}

void Bluetooth::begin(byte outputMax)
{
  Serial.begin(9600);
  
  maxAngle = outputMax;
  curAngle = maxAngle / 2;

  Serial.print("Default angle: ");
  Serial.print(curAngle);
}

void Bluetooth::handleCommand(char* cmd) {
  Serial.print("Received command: ");
  Serial.println(cmd);

  if (strcmp(cmd, "FIRE") == 0) {
    Serial.println("-> Firing!");

  } else if (strcmp(cmd, "WINDUP") == 0) {
    Serial.println("-> Winding up...");

  } else if (strncmp(cmd, "ANGLE ", 6) == 0) {
  int angleInput = atoi(cmd + 6);

  if (angleInput < 0 || angleInput > maxAngle) {
    Serial.print("-> Angle out of bounds: ");
    Serial.println(angleInput);
    curAngle = maxAngle / 2;
  } else {
    curAngle = angleInput;
    Serial.print("-> Set angle to: ");
    Serial.println(curAngle);
  }

  } else {
    Serial.println("-> Unknown command");
  }
}

void Bluetooth::listenForCommands() {
  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n') {
      inputBuffer[bufferIndex] = '\0';  // Null-terminate the string

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

byte Bluetooth::getAngle(){
  return curAngle;
}

// int test() {
//   while (Serial.available()) {
//     char c = Serial.read();

//     if (c == '\n') {
//       inputBuffer[bufferIndex] = '\0';  // Null-terminate the string

//       // Handle the command
//       handleCommand(inputBuffer);

//       // Reset buffer for next message
//       bufferIndex = 0;
//     } else if (c != '\r') {
//       if (bufferIndex < BUFFER_SIZE - 1) {
//         inputBuffer[bufferIndex++] = c;
//       } else {
//         bufferIndex = 0;  // Reset on overflow
//         Serial.println("Error: input too long");
//       }
//     }
//   }
// }
