#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
int foto;
float h;
float t;
float f;
float hif;
float hic;
int pirValor;

DHT dht(DHTPIN, DHTTYPE);

int led = 7;
int PIR = 8;
int analogPin=0;
int valorLDR=0;
char c;

#define ADDRESS 0x08 // Dirección I2C del esclavo

int valorPot = 0;


void requestEvent() {
  Wire.write(valorPot); // Enviar el valor del potenciómetro al maestro
  Serial.print("Valor potenciómetro: ");
  Serial.println(valorPot);
}

void PIRE(){
  pirValor = digitalRead(PIR);

  if(pirValor == HIGH){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}

void fotores(){
    valorLDR=analogRead(analogPin);
    delay(400);

    foto = valorLDR;
}

void temperatura(){
  delay(500);
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);

  hif = dht.computeHeatIndex(f, h);
  hic = dht.computeHeatIndex(t, h, false);

}

void setup() {
  Wire.begin(ADDRESS); // Inicializar el esclavo con la dirección I2C especificada
  Wire.onRequest(requestEvent); // Asignar la función requestEvent() al evento onRequest
  Serial.begin(9600); // Inicializar la comunicación serial
}

void loop() {
  valorPot = analogRead(A0); // Leer el valor del potenciómetro
  delay(100); // Esperar un momento antes de volver a leer el potenciómetro
}