/* 
 
 I2C wire chat
 From: earl@microcontrollerelectronics.com

 Analog Pin 5 SCL
 Analog Pin 4 SDA
 Common ground

*/
#include <Arduino.h>
#include <Wire.h>
#define WireDevice 8

String buffer;
int mode;

void setup() { Serial.begin(9600); }

void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c != '\n') {
      if (c == '\r') continue;
      buffer += c;
      continue;
    }
    else {  
      buffer += '\0';
      if (buffer[0] == '#') {
        if (buffer[1] == 'm') {
          if (mode != 'm') {
            mode = 'm';
            master();
            Serial.println("Master mode");
          }
        }
        if (buffer[1] == 's') {
          if (mode != 's') {
            mode = 's';
            slave();
            Serial.println("Slave mode");
          }
        }
        buffer = "";
        continue;
      }
      if (mode == 'm') {
        Wire.beginTransmission(WireDevice); 
        int i = 0;
        while (buffer[i]) { Wire.write(buffer[i]); i +=1; }
        Wire.endTransmission();    
      }
      else Serial.println("Invalid Mode");
      buffer = "";
    } 
  }
}

void master() {
  Wire.begin();
  Serial.println("Master Initialized");
}

void slave() {
  Wire.begin(8);                
  Wire.onReceive(receiveEvent);
  Serial.println("Slave Initialized");
}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) {
    char c = Wire.read();
    Serial.print(c);     
  }
  char c = Wire.read();
  Serial.println(c);     
}