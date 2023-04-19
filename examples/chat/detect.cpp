#include <Wire.h>
#include <Arduino.h>

const int max_devices = 10; // El máximo número de dispositivos que se pueden detectar
int deviceCount = 0; // El número actual de dispositivos detectados
int devices[max_devices]; // La lista de dispositivos detectados

void setup() {
  Serial.begin(9600); // Inicializa el puerto serie
  Wire.begin(); // Inicializa el bus I2C
}

void loop() {
  byte error, address;

  Serial.println("Escaneando dispositivos I2C...");

  for(address = 1; address < 127; address++ ) {
    // Se intenta comunicar con el dispositivo en la dirección address
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo encontrado en la dirección 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.print(address,HEX);
      Serial.println("  !");

      // Se añade el dispositivo a la lista
      if (deviceCount < max_devices) {
        devices[deviceCount] = address;
        deviceCount++;
      }
      delay(5); // Pequeña pausa para evitar la sobrecarga del bus I2C
    }
    else if (error == 4) {
      Serial.print("Error en la dirección 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }
  }
  
  if (deviceCount == 0) {
    Serial.println("No se encontraron dispositivos.");
  }
  else {
    Serial.print("Dispositivos encontrados: ");
    for (int i = 0; i < deviceCount; i++) {
      Serial.print("0x");
      Serial.print(devices[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }

  delay(5000); // Espera 5 segundos antes de volver a escanear el bus I2C
}
