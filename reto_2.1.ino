int contador=0;


void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), velocidadMenos, RISING);
}

void loop() {
  
}

void velocidadMenos()
{
 contador++;
  Serial.println(contador);
  }
