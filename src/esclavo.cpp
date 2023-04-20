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

void requestEvent() {
  int r = Wire.read();
  if (r == '1')
  {
    Wire.beginTransmission(ADDRESS);
    Wire.write(1);
    Wire.endTransmission();
    delay(500);
    int record = Wire.read();
    Serial.println(record);
  }
  
  
  if (r == '2')
  {
    Wire.beginTransmission(ADDRESS);
    Wire.write(2);
    Wire.endTransmission();
    delay(500);
    int record = Wire.read();
    Serial.println(record);
  }
  
  if (r == '3')
  {
    Wire.beginTransmission(ADDRESS);
    Wire.write(3);
    Wire.endTransmission();
    delay(500);
    int record = Wire.read();
    Serial.println(record);
  }
  
  if (r == '4')
  {
    Wire.beginTransmission(ADDRESS);
    Wire.write(4);
    Wire.endTransmission();
    delay(500);
    int record = Wire.read();
    Serial.println(record);
  }
  if (r == '5')
  {
    Wire.beginTransmission(ADDRESS);
    Wire.write(5);
    Wire.endTransmission();
    delay(500);
    int record = Wire.read();
    Serial.println(record);
  }
  if (r == '6')
  {
    // Indice de temperatura en grados centigrados
    Wire.beginTransmission(ADDRESS);
    Wire.write(6);
    Wire.endTransmission();
    delay(500);
    int record = Wire.read();
    Serial.println(record);
    // Serial.print("Prueba 6");
  }
  if (r == '7')
  {
    Wire.beginTransmission(ADDRESS);
    Wire.write(7);
    Wire.endTransmission();
    delay(500);
    int record = Wire.read();
    Serial.println(record);
  }
  

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


  
  // Wire.write(valorPot); // Enviar el valor del potenciómetro al maestro
  // Serial.print("Valor potenciómetro: ");
  // Serial.println(valorPot);