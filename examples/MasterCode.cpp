#include <Arduino.h>
#include <Wire.h>
# define I2C_SLAVE1_ADDRESS 11
# define I2C_SLAVE2_ADDRESS 12
#define PAYLOAD_SIZE 2
int n=0;
void setup()
{
 	Wire.begin(); 							
 	Serial.begin(9600); 	
 	Serial.println(F("-------------------------------------I am the Master"));
 	delay(1000);

 	//Request value of n to slave
 	Wire.requestFrom(I2C_SLAVE1_ADDRESS, 1); 		
 	n = Wire.read();
 	Serial.print(F("recieved value : "));
 	Serial.println(n);

 	//Send value 12 to slave
 	Wire.beginTransmission(I2C_SLAVE1_ADDRESS);
 	Wire.write(12);
 		Serial.print(F("sending value : "));
 	Serial.println(12); 													
 	Wire.endTransmission(); 		
 	Serial.print(" ");

 	//Request value of n to slave after change
 	Wire.requestFrom(I2C_SLAVE1_ADDRESS, 1);
 	n = Wire.read();
 	Serial.print(F(" new recieved value : "));
 	Serial.println(n);
}

void loop()
{
 	delay(100);
}