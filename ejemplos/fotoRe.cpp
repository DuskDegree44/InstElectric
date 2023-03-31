#include <Arduino.h>
//Identificar el valor de la luz
int analogPin=0;
int valorLDR=0;
void setup(){
    Serial.begin(9600);
}
void loop(){
    valorLDR=analogRead(analogPin);
    Serial.println(valorLDR);
    delay(400);
}