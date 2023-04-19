#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>   // Librería para la comunicación I2C 
#include <DHT.h> // Incluimos librería sensor de temperatura
#include <LinkedList.h>
#define DHTPIN 2 // Definimos el pin digital donde se conecta el sensor
#define DHTTYPE DHT11 // Dependiendo del tipo de sensor
#define SLAVE_ADDRESS 0x08 // Direccion de el esclavo
int foto; 
float h; // Leemos la humedad relativa
float t; // Leemos la temperatura en grados centígrados (por defecto)
float f; // Leemos la temperatura en grados Fahreheit
float hif; // Calcular el índice de calor en Fahreheit
float hic;// Calcular el índice de calor en grados centígrados
int pirValor; //Variable para el valor del Sensor.
LinkedList<int> slaveAdresses;
//int slaveAdresses[];

// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

int led = 7; //PIN usado para luces / transistor
int PIR = 8; //PIN usado para Sensor
int analogPin=0; //Fotorres var
int valorLDR=0; //fotorres var
//char c;

void setup() {
  pinMode(led,OUTPUT); //Declaramos el LED de tipo salida
  pinMode(PIR,INPUT); //Declaramos al sensor de tipo entrada
  dht.begin();
  Wire.begin();
  Serial.begin(9600);
  //Wire.onRequest(commun);

  void buscarEsclavos();

}

/*
---------------
---Funciones---
---------------
*/
#pragma region Funciones
void PIRE(){
  pirValor = digitalRead(PIR); //Obtenemos el valor del sensor

  if(pirValor == HIGH){ // Comparamos el valor si es HIGH esta detectando un movimiento de lo  contrario enviaria un LOW (Tambien pueden comprarse con 0,1)
    digitalWrite(led,HIGH); // SI el valor es igual a HIGH, encendemos el LED
  }
  else{
    digitalWrite(led,LOW); //Si el valor es diferente de HIGH apagamos el LED.
  }

}

void fotores(){
    valorLDR=analogRead(analogPin);
    delay(400);

    foto = valorLDR;
}


void temperatura()
{
      
  delay(500);
  //Esperamos 5 segundos entre medidas
  // Leemos la humedad relativa
  h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  t = dht.readTemperature();
  // Leemos la temperatura en grados Fahreheit
  f = dht.readTemperature(true);
 
  // Calcular el índice de calor en Fahreheit
  hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  hic = dht.computeHeatIndex(t, h, false);
 
  
}

void commun(){
  Wire.requestFrom(SLAVE_ADDRESS, 10);
  int Val = Wire.read();
}

void buscarEsclavos()
{
    int error;
    for(int i = 0; i < 127; i++)
    {
        Wire.beginTransmission(i);
        error = Wire.endTransmission();
        if(error == 0)
        {
            slaveAdresses.add(i);
        }
    }
}

#pragma endregion
// Fin Funciones


void loop() {
  // Serial.println("Vuelta"); 
  #pragma region Serial
  int r = Serial.read(); //Sensores conectados al maestro
  if (r == '1')
  {
    // Fotorresistencia 
    fotores();
    Serial.println(foto);
    // Serial.print("Prueba 1");
  }
  
  
  if (r == '2')
  {
    // Humedad
    temperatura();
    Serial.print(String(h));
    // Serial.print("Prueba 2");
  }
  
  if (r == '3')
  {
    // Temperatura en grados centigrados
    temperatura();
    Serial.print(String(t));
    // Serial.print("Prueba 3");
  }
  
  if (r == '4')
  {
    // Temperatura en grados fahreheit
    temperatura();
    Serial.print(String(f));
    // Serial.print("Prueba 4");
  }
  if (r == '5')
  {
    // Indice de temperatura en grados fahreheit
    temperatura();
    Serial.print(String(hif));
    // Serial.print("Prueba 5");
  }
  if (r == '6')
  {
    // Indice de temperatura en grados centigrados
    temperatura();
    Serial.print(String(hic));
    // Serial.print("Prueba 6");
  }

  if (r == '7')
  {
    // Sensor pirolico de movimiento
    PIRE();
    Serial.println(pirValor);
    // Serial.print("Prueba 1");
  }
#pragma endregion
  
  if(r == 'E')
  {
        for(int i = 0; i < slaveAdresses.size(); i++)
        {
            Serial.print(slaveAdresses.get(i) + " ");
        }
        Serial.println(" Esclavos");
  }

    if(r == 'R')
    {
        int f = Serial.read();
    }
}