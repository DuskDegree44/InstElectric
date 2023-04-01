#include <Wire.h>   // Librería para la comunicación I2C
#include <Arduino.h>
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
