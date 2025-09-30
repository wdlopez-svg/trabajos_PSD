const int led1 = 10;  
const int led2 = 7;  
const int led3 = 8;  
const int led4 = 9;  
const int boton = 2; 

void setup() { 
  Serial.begin(9600);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(boton, INPUT);  
}

void loop() {
  int peatones=digitalRead(boton);
 digitalWrite(led2, HIGH);
  if(peatones==HIGH){
    digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);
    delay(1500);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led1, HIGH);
    delay(5000);
     digitalWrite(led4, LOW);
    digitalWrite(led1, LOW);
  }
  
 
 int boton_estado = digitalRead(boton);
 
}
  

