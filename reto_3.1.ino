#include <EEPROM.h>
int contador=0;
int direccion=0;

void setup() {
  Serial.begin(9600);
  contador=EEPROM.read(direccion);
  contador++;
  EEPROM.write(direccion, contador);
  Serial.print("numero de encendidos: ");
  Serial.println(contador);
}

void loop() {
}
