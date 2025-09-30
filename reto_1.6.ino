const int led1 = 6; 
const int led2 = 7; 
const int led3 = 8; 
const int led4 = 9; 
const int led5 = 10; 
const int boton1 = 11;
const int boton2 = 2;
const int boton3 = 3;
const int boton4 = 4;
const int boton5 = 5;
int numero_secuencia = 1;
int ant_1=LOW;
int ant_2=LOW;
int ant_3=LOW;
int ant_4=LOW;
int ant_5=LOW;

void setup() { 
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(boton1, INPUT); 
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  pinMode(boton4, INPUT);
  pinMode(boton5, INPUT);
}

void loop() {
 
 String secuencia1= "";
String secuencia2= "";
  int leds[numero_secuencia];
  
  for (int i=0;i < sizeof(leds) / sizeof(leds[0]);i++){
    leds[i]=random(1,6);
    if (i==0){
    secuencia1+=String(leds[i]);}
    if(i>0){
    if (leds[i]==leds[i-1]){
      i--;
    }else{secuencia1+=String(leds[i]);}
    }
  }
  for (int i=0;i < sizeof(leds) / sizeof(leds[0]);i++){
    if(leds[i]==1){
    digitalWrite(led1, HIGH);
    }
    if(leds[i]==2){
    digitalWrite(led2, HIGH);
    }
    if(leds[i]==3){
    digitalWrite(led3, HIGH);
    }
    if(leds[i]==4){
    digitalWrite(led4, HIGH);
    }
    if(leds[i]==5){
    digitalWrite(led5, HIGH);
    }
    delay(1000);
      digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  }
 
    
  int a=1;
  while(a<=numero_secuencia){
    int arreglo2[numero_secuencia];
    
    
    int boton2_estado = digitalRead(boton2);
    int boton3_estado = digitalRead(boton3);
    int boton4_estado = digitalRead(boton4);
    int boton5_estado = digitalRead(boton5);
   int boton1_estado = digitalRead(boton1);
    
    if (boton1_estado==HIGH && ant_1==LOW){
      int b=1;
   while(b==1){
     secuencia2+="1";
      
      ant_1=boton1_estado;
      b++;
    }
      a++;
    }
    
    
    
    if (boton2_estado==HIGH && ant_2==LOW){
      int C=1;
   while(C==1){
     secuencia2+="2";
      
      ant_2=boton2_estado;
      C++;
    }
      a++;
    }
    
    
    
     if (boton3_estado==HIGH && ant_3==LOW){
      int d=1;
   while(d==1){
     secuencia2+="3";
     
      ant_3=boton3_estado;
      d++;
    }
      a++;
    }
    
    
    
     if (boton4_estado==HIGH && ant_4==LOW){
      int e=1;
   while(e==1){
     secuencia2+="4";
      
      ant_4=boton4_estado;
      e++;
    }
      a++;
    }
    
    
    
    if (boton5_estado==HIGH && ant_5==LOW){
      int f=1;
   while(f==1){
     secuencia2+="5";

      ant_5=boton5_estado;
      f++;
    }
      a++;
    }
    
    
    
    ant_1=boton1_estado;
    ant_2=boton2_estado;
    ant_3=boton3_estado;
    ant_4=boton4_estado;
    ant_5=boton5_estado;
  }
  Serial.println(secuencia1);
  Serial.println(secuencia2);
  if(secuencia1==secuencia2){
     numero_secuencia++;
  }else{
    digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
    delay(250);
    digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
    delay(250);
     digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
    delay(250);
     digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
    delay(250);
     digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
    delay(250);
     digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
    delay(1000);
    numero_secuencia=1;
  }
}