const int led1 = 6; 
const int boton1 = 2;
const int boton2 = 3;
int brillo=0;


void setup() { 
  Serial.begin(9600);
   pinMode(led1, OUTPUT);
   pinMode(boton1, INPUT); 
   pinMode(boton2, INPUT);  
}

void loop() {
 
  int boton1_estado = digitalRead(boton1);
  int boton2_estado = digitalRead(boton2);
  
  if (boton1_estado==HIGH){
     if (brillo <255){
    brillo ++;
     }
     Serial.println(brillo);
    analogWrite(led1, brillo);
  }
  if(boton2_estado==HIGH){
    if (brillo >0){
   brillo --;
    }
     Serial.println(brillo);
      analogWrite(led1, brillo);
  }
}