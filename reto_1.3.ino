const int led1 = 6;  
const int led2 = 7;  
const int boton1 = 1; 
const int boton2 = 2; 

void setup() { 
   pinMode(led1, OUTPUT);  
   pinMode(led2, OUTPUT);  
   pinMode(boton1, INPUT);  
   pinMode(boton2, INPUT);  
}

void loop() {
 int boton_estado1 = digitalRead(boton1);
 int boton_estado2 = digitalRead(boton2);
  
   if (boton_estado1==HIGH) {
 int stop=0;
     do{
       int stop=0;
       digitalWrite(led1, HIGH);
      delay(1000);
       digitalWrite(led1, LOW);
       digitalWrite(led2, HIGH);
       delay(1000);
       digitalWrite(led2, LOW);
       boton_estado2 = digitalRead(boton2);
     }while(boton_estado2 == LOW);
    }
  }
