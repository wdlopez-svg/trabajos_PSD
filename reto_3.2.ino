#include <EEPROM.h>
int amarillo=11;
int azul=12;
int rojo=13;
char estado;

void setup() {
  Serial.begin(9600);
 
  pinMode(amarillo,OUTPUT);
  pinMode(azul,OUTPUT);
  pinMode(rojo,OUTPUT);
  Serial.println("escriba para hacer: ");
  Serial.println("1. encender led amarillo: ");
  Serial.println("2. encender led azul: ");
  Serial.println("3. encender led rojo: ");
  EEPROM.get(0,estado);
  menu(estado);
}


void loop() {
   
  estado = Serial.read();
   menu(estado);
  
}
void menu(char estado){
  switch(estado){
      case '1':
      digitalWrite(amarillo, HIGH);
      digitalWrite(azul, LOW);
      digitalWrite(rojo, LOW);
      EEPROM.put(0, estado);
    break;
    case '2':
      digitalWrite(amarillo, LOW);
      digitalWrite(azul, HIGH);
      digitalWrite(rojo, LOW);
      EEPROM.put(0, estado);
    break;
    case '3':
      digitalWrite(amarillo, LOW);
      digitalWrite(azul, LOW);
      digitalWrite(rojo, HIGH);
      EEPROM.put(0, estado);
    break;
  }
}