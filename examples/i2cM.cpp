#include <Arduino.h>
#include <Wire.h>
int cont=0; //variable de conteo 
void setup() {
Wire.begin(); //inicio de comunicación i2c
Serial.begin(9600);
}

void loop() {
 cont++; //incremento de variable
 Wire.beginTransmission(4); // configuración de esclavo a enviar
 Wire.write(cont);  // envio de mensaje
 Wire.endTransmission(); // fin de comunicación
 delay(1000); // espera

 Wire.requestFrom(4, 2); 
 while(Wire.available()){
  Serial.println("mesaje recibido");
    char c = Wire.read();
  Serial.println(c);
 }
Serial.println();
 delay(1000);
}#include <Arduino.h>
// Dirección del dispositivo esclavo (puede variar según el dispositivo)
#define SLAVE_ADDRESS 0x08

void setup() {
  // Inicializar la comunicación serial para la depuración
  Serial.begin(9600);

  // Inicializar la comunicación I2C
  Wire.begin();
}

void loop() {
  // Enviar un mensaje al dispositivo esclavo
  Wire.beginTransmission(SLAVE_ADDRESS);  // Iniciar la transmisión
  Wire.write("Hola, dispositivo esclavo!");  // Enviar el mensaje
  Wire.endTransmission();  // Finalizar la transmisión

  // Esperar 1 segundo antes de enviar el siguiente mensaje
  delay(1000);
}
