#include <Wire.h>   // Librería para la comunicación I2C
#include <Arduino.h>
// Dirección del dispositivo esclavo (que debe coincidir con la dirección del maestro)
#define SLAVE_ADDRESS 0x08

void setup() {
  // Inicializar la comunicación serial para la depuración
  Serial.begin(9600);

  // Inicializar la comunicación I2C y definir la función para recibir solicitudes
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendData);
}

void loop() {
  // Esperar a que llegue una solicitud del maestro
}

// Función para enviar datos solicitados por el maestro
void sendData() {
  // Definir el mensaje a enviar
  String message = "Hola, maestro! Soy el dispositivo esclavo.";

  // Enviar el mensaje al maestro
  Wire.write(message.c_str());
}