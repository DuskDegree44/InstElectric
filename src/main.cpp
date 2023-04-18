#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>   // Librería para la comunicación I2C
// Incluimos librería sensor de temperatura
#include <DHT.h>
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
// Direccion de el esclavo
#define SLAVE_ADDRESS 0x08
int foto;
// Leemos la humedad relativa
float h;
// Leemos la temperatura en grados centígrados (por defecto)
float t;
// Leemos la temperatura en grados Fahreheit
float f;
// Calcular el índice de calor en Fahreheit
float hif;
// Calcular el índice de calor en grados centígrados
float hic;
int pirValor; //Variable para el valor del Sensor.

/*
---------------
---Variables---
---------------
*/
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

int led = 7; //PIN usado para luces / transistor
int PIR = 8; //PIN usado para Sensor
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
  Serial.begin(9600);
  //Wire.onRequest(commun);
}

/*
---------------
---Funciones---
---------------
*/
void PIRE(){
  pirValor = digitalRead(PIR); //Obtenemos el valor del sensor

  if(pirValor == HIGH){ // Comparamos el valor si es HIGH esta detectando un movimiento de lo  contrario enviaria un LOW (Tambien pueden comprarse con 0,1)
    digitalWrite(led,HIGH); // SI el valor es igual a HIGH, encendemos el LED
  }
  else{
    digitalWrite(led,LOW); //Si el valor es diferente de HIGH apagamos el LED.
  }

  // Serial.print("Valor de PIR: ");
  // Serial.println(pirValor);
  // Serial.println("-----------------------------------------");
  // Serial.println("");
}

void fotores(){
    valorLDR=analogRead(analogPin);
    // Serial.print("Valor de fotorresistencia: ");
    // Serial.println(valorLDR);
    // Serial.println("-----------------------------------------");
    delay(400);

    foto = valorLDR;
}
//enum eTemp{
  //hum, tempC, tempF,hiC, hiF 
//};
void temperatura(){
      // Esperamos 5 segundos entre medidas
  delay(500);
 
  // Leemos la humedad relativa
  h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  t = dht.readTemperature();
  // Leemos la temperatura en grados Fahreheit
  f = dht.readTemperature(true);
 
  // Comprobamos si ha habido algún error en la lectura
  /*if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    Serial.println('--------------------');
    //return;
  }*/
 
  // Calcular el índice de calor en Fahreheit
  hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  hic = dht.computeHeatIndex(t, h, false);
 
  // Serial.print("Humedad: ");
  // Serial.print(h);
  // Serial.print(" %\t");
  // Serial.println("");
  // Serial.println("-----------------------------------------");
  // Serial.print("Temperatura: ");
  // Serial.print(t);
  // Serial.print(" *C ");
  // Serial.print(f);
  // Serial.print(" *F\t");
  // Serial.println("");
  // Serial.println("-----------------------------------------");
  // Serial.print("Indice de calor: ");
  // Serial.print(hic);
  // Serial.print(" *C ");
  // Serial.print(hif);
  // Serial.println(" *F");
  // Serial.println("-----------------------------------------");
}

// String commun(String message){
//   /*
//   Diccionario:
//   Temperatura : Regresa la temperatura
  
  
//   */
//   // Definir el mensaje a enviar
//   //String message = "Hola, maestro! Soy el dispositivo esclavo.";
  
//   // Enviar el mensaje al maestro
//   Wire.write(message.c_str());

//   // Solicitar datos al dispositivo esclavo
//   Wire.requestFrom(SLAVE_ADDRESS, 10);  // Solicitar 10 bytes al esclavo
//   String s = ""; 
//   // Leer los datos enviados por el esclavo
//   while (Wire.available()) {
//     c = Wire.read();
//     s = s + c;
//     Serial.print(c);
//   }
//   Serial.println();
//   delay(50);
//   return s;//Regresa una string
//   //delay(5000);  // Esperar 5 segundos antes de hacer otra solicitud
// }
void loop() {
  // Serial.println("Vuelta");
  int r = Serial.read();
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
  /* 
  //  este while hace que no reaccione correctamente
  //  el puerto serial 

  while (Serial.available())
  {
    //code
    // if (r == 'T')
    // {
    //   code
    //   float *tempe = temperatura();
    //   float v1 = tempe[0]; 
    //   float v2 = tempe[1];
    //   float v3 = tempe[2];

    //   int v11 = v1.toInt();
    //   String v22 = String(v2);
    //   String v33 = String(v3);

    //   Serial.write(v1.toInt());
    //   Serial.write(v22);
    //   Serial.write(v33);
    // }

    // if (r == 'P')
    // {
    //   int p = PIRE();
    //   Serial.write(p);
    // }

    if (r == '1')
    {
      // Fotorresistencia 
      fotores();
      Serial.println(foto);
      Serial.print("Prueba 1");
    }
    
    if (r == '7')
    {
      // Sensor pirolico de movimiento
      PIRE();
      Serial.println(pirValor);
      Serial.print("Prueba 1");
    }
    
    if (r == '2')
    {
      // Humedad
      temperatura();
      Serial.print(String(h));
      Serial.print("Prueba 2");
    }
    
    if (r == '3')
    {
      // Temperatura en grados centigrados
      temperatura();
      Serial.print(String(t));
      Serial.print("Prueba 3");
    }
    
    if (r == '4')
    {
      // Temperatura en grados fahreheit
      temperatura();
      Serial.print(String(f));
      Serial.print("Prueba 4");
    }

    if (r == '5')
    {
      // Indice de temperatura en grados fahreheit
      temperatura();
      Serial.print(String(hif));
      Serial.print("Prueba 5");
    }

    if (r == '6')
    {
      // Indice de temperatura en grados centigrados
      temperatura();
      Serial.print(String(hic));
      Serial.print("Prueba 6");
    }

  } */

}

void commun(){
  Wire.requestFrom(SLAVE_ADDRESS, 10);
  int Val = Wire.read();
}