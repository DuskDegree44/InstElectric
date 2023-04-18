#include <Arduino.h>
#include <Wire.h>
void setup()
{
  Wire.begin(4);     // id de esclavo           
  Wire.onReceive(receiveEvent);  //evento de recepción de mensajes
  Wire.onRequest(requestEvent);
  Serial.begin(9600);   // comunicación serial        
}

void loop()
{
delay(100);
}
void receiveEvent(int bytes){ // evento i2c
  while(Wire.available())  // si existe mensaje por leer
  {
    Serial.println("mensaje recibido");
    int c = Wire.read();  // recibe dato
    Serial.print(c);    //envia por comunicación serial 
  }
}
// function that executes whenever data is requested from master
void requestEvent() {
 Wire.write("Hi");  /*send string on request */
}