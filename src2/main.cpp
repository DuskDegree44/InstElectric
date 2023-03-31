// #include <Wire.h>   // Librería para la comunicación I2C
#include <Arduino.h>
// // Dirección del dispositivo esclavo (que debe coincidir con la dirección del maestro)
// #define SLAVE_ADDRESS 0x08

// void setup() {
//   // Inicializar la comunicación serial para la depuración
//   Serial.begin(9600);

//   // Inicializar la comunicación I2C y definir la función para recibir solicitudes
//   Wire.begin(SLAVE_ADDRESS);
//   Wire.onRequest(sendData);
// }

// void loop() {
//   // Esperar a que llegue una solicitud del maestro
// }

// // Función para enviar datos solicitados por el maestro
// void sendData() {
//   // Definir el mensaje a enviar
//   String message = "Hola, maestro! Soy el dispositivo esclavo.";

//   // Enviar el mensaje al maestro
//   Wire.write(message.c_str());
// }

#include <Wire.h>   // Librería para la comunicación I2C

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