#include <Arduino.h>
#include <Wire.h>   // Librería para la comunicación I2C
// Incluimos librería sensor de temperatura
#include <DHT.h>
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
// Direccion de el esclavo
#define SLAVE_ADDRESS 0x08

/*
---------------
---Variables---
---------------
*/
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

int led = 7; //PIN usado para lED
int PIR = 8; //PIN usado para Sensor
int valor; //Variable para el valor del Sensor.
int analogPin=0; //Fotorres var
int valorLDR=0; //fotorres var
char c;


/*
------------------
---Setup y loop--
------------------
*/
void setup() {
  pinMode(led,OUTPUT); //Declaramos el LED de tipo salida
  pinMode(PIR,INPUT); //Declaramos al sensor de tipo entrada
  dht.begin();
  Wire.begin();
  Wire.onRequest(commun);
}

void loop() {

}


/*
---------------
---Funciones---
---------------
*/
int PIRE(){
  valor = digitalRead(PIR); //Obtenemos el valor del sensor

  if(valor == HIGH){ // Comparamos el valor si es HIGH esta detectando un movimiento de lo  contrario enviaria un LOW (Tambien pueden comprarse con 0,1)
    digitalWrite(led,HIGH); // SI el valor es igual a HIGH, encendemos el LED
  }
  else{
    digitalWrite(led,LOW); //Si el valor es diferente de HIGH apagamos el LED.
  }

  Serial.print('Valor de PIR: ');
  Serial.print(valor);
  Serial.println('--------------------');

  return valor;
}

int fotores(){
    valorLDR=analogRead(analogPin);
    Serial.print('Valor de fotorresistencia: ');
    Serial.println(valorLDR);
    Serial.println('--------------------');
    delay(400);

    return valorLDR;
}

float temperatura(){
      // Esperamos 5 segundos entre medidas
  delay(5000);
 
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahreheit
  float f = dht.readTemperature(true);
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    Serial.println('--------------------');
    return;
  }
 
  // Calcular el índice de calor en Fahreheit
  float hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);
 
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  Serial.println('--------------------');

  return h, t, f, hic, hif;
}

void commun(){
  // Definir el mensaje a enviar
  String message = "Hola, maestro! Soy el dispositivo esclavo.";

  // Enviar el mensaje al maestro
  Wire.write(message.c_str());

  // Solicitar datos al dispositivo esclavo
  Wire.requestFrom(SLAVE_ADDRESS, 10);  // Solicitar 10 bytes al esclavo

  // Leer los datos enviados por el esclavo
  while (Wire.available()) {
    c = Wire.read();
    Serial.print(c);
  }
  Serial.println();
  
  delay(5000);  // Esperar 5 segundos antes de hacer otra solicitud
}