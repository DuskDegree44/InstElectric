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

// Codigo ejemplo para hacer algo si se detecta algo en la fotorresistencia
// int analogPin=0;
// int valorLDR=0;
// int umbralNumber=900;// Ejemplo puede ser cualquier numero deseable
// int LED=13;
// void setup(){
//   pinMode(LED, OUTPUT);
//   Serial.begin(9600);
// }
// void loop(){
//   valorLDR=analogRead(analogPin);
//   if (valorLDR >= umbralNumber){
//     digitalWrite(LED, HIGH);
//   }
//   else{
//     digitalWrite(LED, LOW);
//   }
// }
