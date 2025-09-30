int sensor=2;
int apagar=3;
int alarma=13;
bool estado_alarma;
int frecuencia=1;
void setup() { 
  Serial.begin(9600);
  pinMode(alarma, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(sensor), activado,RISING);
  attachInterrupt(digitalPinToInterrupt(apagar), apagado,RISING);
  noInterrupts();
  TCCR2A=0;
  TCCR2B=0;
  TCCR2A |= B00000010;
  OCR2A=frecuencia;
  TCCR2B |= B00000100;
  TIMSK2 |= B00000010;
  interrupts();
} 
void loop() {
  if(frecuencia>=255){
    while(frecuencia>0){
    frecuencia--;
    }
  }
  if(frecuencia<=0){
    while(frecuencia<255){
    frecuencia++;
    }
  }
} 
void activado(){
  estado_alarma=true;
  
}
void apagado(){
  estado_alarma=false;
  frecuencia=1;
  digitalWrite(alarma, LOW);
  
}
ISR(TIMER2_COMPA_vect){
  if (estado_alarma){
    if (frecuencia<255){
      frecuencia++;}
    analogWrite(alarma, frecuencia);
    Serial.println(frecuencia);
  }
}
