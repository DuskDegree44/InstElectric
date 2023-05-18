#include <Wire.h>
#include <Arduino.h>
int FRE;
int FR;
int TMP;
int PIR;
int TR;
int TP;
#include <LinkedList.h>

LinkedList<int> slaveAdres;

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  FRE = analogRead(0);
  FR = map(FRE, 1017, 344, 0, 100);
  TP = analogRead(1);
  TMP = map(TP, 358, 20, 100, 0);
  PIR = digitalRead(11);
  
  int rec = Serial.read();
  
  switch(rec) {
    // Si se recibe un carácter 'A' se enciende el led rojo
    case 'T':
    	Serial.println(TMP);
      	break;
    // Si se recibe un carácter 'B' se enciende el led verde
    case 'F':
    	Serial.println(FR);
    	break;
    case 'P':
    	Serial.println(PIR);
    	break;
    case 'E':
      byte error, address;
      //int deviceCount;
      Serial.println('Scanning... ');
      for (address = 1; address < 127; address++)
      {
        /* code */
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0)
        {
          /* Si hay comunicación */
          //deviceCount = deviceCount + 1;
          Serial.println('Found address 0x');
          if(address < 16) Serial.print('0');
          Serial.print(address, HEX);
          Serial.println("");
        }
        else if (error == 4)
        {
          /* code */
          Serial.print("error at addess");
        }
        for(int i = 0; i < slaveAdres.size(); i++)
        {
          /* code */
          Serial.println(slaveAdres.get(i));
          Serial.println(" Esclavos ");
        }
      }
      break;
  }	
  
  if(rec == 'A'){
    Serial.println("enviando... ");
    Wire.beginTransmission(1); // Iniciar la comunicación con el esclavo de dirección 8
    Wire.write('A'); // Escribir el mensaje en el buffer de transmisión
    Wire.endTransmission(); // Finalizar la transmisión
    Wire.requestFrom(1, 3);
  	while (Wire.available()) {
    	int data = Wire.read(); // Leer el byte recibido del dispositivo esclavo
    	Serial.println(data); // Imprimir el valor recibido en el puerto serie
  	}
  }
    if(rec == 'B'){
    Serial.println("enviando... ");
      
    Wire.beginTransmission(1); // Iniciar la comunicación con el esclavo de dirección 8
    Wire.write('B'); // Escribir el mensaje en el buffer de transmisión
    Wire.endTransmission(); // Finalizar la transmisión
      
    int lectura = Wire.read();
    Serial.println(lectura);
  }
}



