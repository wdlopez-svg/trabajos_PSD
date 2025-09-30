int contador=0; 
int boton=2; 
void setup() { 
  pinMode(13, OUTPUT); // pin 13 como salida para LED incorporado 
  noInterrupts(); // detiene interrupciones 
  TCCR1A = 0; // reset de registro de control A de Timer 1 
  TCCR1B = 0; // reset de registro de control B de Timer 1 
  TCCR1B |= B00000100; // bit CS12 para activar prescaler a 256 
  TIMSK1 |= B00000010; // bit OCIE1 para indicar a OCR1A para la comparacion 
  OCR1A = 15625*4; // valor calculado que genera la interrupcion cada 500 ms. 
  interrupts(); // vuelve a habilitar las interrupciones 
  pinMode(boton, INPUT); 
  Serial.begin(9600); 
  attachInterrupt(digitalPinToInterrupt(2), interrupcion, RISING); 
} 
void loop() {
} 
ISR(TIMER1_COMPA_vect){ // funcion 
    TCNT1 = 0; // Timer 1 a cero 
  Serial.print("la frecuencia es: ");
  Serial.print(contador); 
  Serial.println(" Hz"); 
  contador=0; 
} 
void interrupcion() { 
  contador++; 
}