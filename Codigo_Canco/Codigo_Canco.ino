#include <SoftwareSerial.h>
SoftwareSerial I2CBT(10, 11);
// El TX del módulo BT va al pin 10 del Arduino
// El RX del módulo BT va al pin 11 del Arduino

const int ledPin = 13; // el LED se conecta al pin digital 13
const int motPin = 3; // la base del transistor se conecta al pin digital 3
int incomingByte;    // variable que se usa para los datos que introducimos en el serial buffer

void setup() {
  I2CBT.begin(9600); // inicializa la comunicación con el módulo Bluetooth
  Serial.begin(9600); // inicializa la comunicación con el puerto serie
  pinMode(motPin, OUTPUT); // inicializa el motor como una salida
  pinMode(ledPin, OUTPUT); // inicializa el LED como una salida
}

void loop() {
 
  // comprobamos si hay datos de entrada
  if (I2CBT.available() > 0) {
  // lectura del byte más antiguo del módulo Bluetooth
  incomingByte = I2CBT.read();

 
  // si recibe una H mayúscula, enciende el LED
  if (incomingByte == 'H') {
    digitalWrite(ledPin, HIGH);
  }
  // si recibe una L mayúscula, apaga el LED
  if (incomingByte == 'L') {
    digitalWrite(ledPin, LOW);
  }
  // si recibe una E mayúscula, enciende el motor
    if (incomingByte == 'E') {
    digitalWrite(motPin, HIGH);
  }
  // si recibe una A mayúscula, apaga el motor
  if (incomingByte == 'A') {
    digitalWrite(motPin, LOW);
  }
  }
}

