

void setup() {
 pinMode(13, OUTPUT);     	
 noInterrupts();          
 TCCR1A = 0;              	
 TCCR1B = 0;              	
 TCCR1B |= B00000100;     	
 TIMSK1 |= B00000010;     	
 OCR1A = 31250;           	
 interrupts();            	
}
void loop() {
 	
}

ISR(TIMER1_COMPA_vect){                
 TCNT1 = 0;                             
 digitalWrite(13,!digitalRead(13));     
}