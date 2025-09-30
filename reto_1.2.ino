int boton = 2; 
int leds[]={6,7,8,9,10,11,12,13};
bool estado_leds[8];

 

void setup() { 
  Serial.begin(9600);
   pinMode(leds[1], OUTPUT);  
   pinMode(leds[2], OUTPUT);  
   pinMode(leds[3], OUTPUT);  
   pinMode(leds[4], OUTPUT);  
   pinMode(leds[5], OUTPUT);  
   pinMode(leds[6], OUTPUT);  
   pinMode(leds[7], OUTPUT);  
   pinMode(leds[0], OUTPUT);  
   pinMode(boton, INPUT);
}

void loop() {
 
   
  int boton_estado=digitalRead(boton);
  while(boton_estado==HIGH){
  
  for (int i=0; i<8 ; i++){
    
    digitalWrite(leds[i],HIGH);
    estado_leds[i]=true;
     Serial.println("el led " + String(i) + " esta en " + String(estado_leds[i]));
    boton_estado=digitalRead(boton);
  
      delay(500);
    if(boton_estado==LOW){
      i=8;
  }
  }
  } 
  for (int i=7; i>=0 ; i--){

    if(estado_leds[i]==true){
         
    digitalWrite(leds[i],LOW);
      digitalWrite(leds[i],false);
      delay(500);
    }
    
    boton_estado=digitalRead(boton);
    if(boton_estado==HIGH){
      i=0;
  }
  } 
  
  
}



