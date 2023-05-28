#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,8); // es el tx y rx del bluetooth
char myChar;
//Declaración led
int led = 13;
int ledV = 2;
int ledA = 3;
int ledR = 4;
int pir = 12; // terminal del sensor pir
int pirdato;

void setup() {
  mySerial.begin(9600);
  mySerial.println("CONEXIÓN EXITOSA");
  pinMode(led, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(pir, INPUT); 
}
void loop() {
 pirdato = digitalRead(pir);
 if(pirdato == HIGH){
   digitalWrite(led, HIGH);
 }
 delay(10);

 if(mySerial.available()){
    myChar = mySerial.read();
    switch(myChar){
      case 'a':  //se enciende el led verde
      digitalWrite(ledV, HIGH);
      break;
      case 'A':   //se apaga el led verde
      digitalWrite(ledV, LOW);
      break;

      case 'b':  //se enciende el led amarillo
      digitalWrite(ledA, HIGH);
      break;
      case 'B':   //se apaga el led amarillo
      digitalWrite(ledA, LOW);
      break;

      case 'c':   //se enciende el led rojo
      digitalWrite(ledR, HIGH);
      break;
      case 'C':   //se apaga el led rojo
      digitalWrite(ledR, LOW);
      break;

      case 'd': //se encienden todas las leds
      digitalWrite(ledV, HIGH);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledR, HIGH);
      break;
      case 'D':   //se apagan todas las leds
      digitalWrite(ledV, LOW);
      digitalWrite(ledA, LOW);
      digitalWrite(ledR, LOW);
      break;
      
      case '3':  //se apaga el sensor pir
      digitalWrite(led, LOW);
      digitalWrite(pir, LOW);
      break;

      default:
      mySerial.println("Se ha apagado el sensor pir");
      break;
  }
 }
}