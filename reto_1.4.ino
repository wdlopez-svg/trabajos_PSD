const int led1 = 6;  
const int led2 = 7;  
const int led3 = 8;  
const int led4 = 9;  
const int boton = 2; 
int ultimo_estado=HIGH;
int residuo;
int dividendo;
int cociente;
 int cuenta=0;

void setup() { 
  Serial.begin(9600);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(boton, INPUT);  
}

void loop() {
 
 int boton_estado = digitalRead(boton);
  if (cuenta>15){
    cuenta =0;
  }
  if (boton_estado==LOW && ultimo_estado== HIGH){
    if (cuenta<=15){
      int modulos[4];
      dividendo = cuenta;
      for (int i=0; i<4;i++){
        modulos[i]=dividendo%2;
        cociente= dividendo/2;
        dividendo=cociente;
         }
      
        if(modulos[0]==1){
        digitalWrite(led1, HIGH);
          Serial.println(1);
        }else{
          digitalWrite(led1, LOW);
          Serial.println(0);
        }
        if(modulos[1]==1){
        digitalWrite(led2, HIGH);
          Serial.println(1);
         }else{
          digitalWrite(led2, LOW);
          Serial.println(0);
        }if(modulos[2]==1){
        digitalWrite(led3, HIGH);
          Serial.println(1);
        }else{
          digitalWrite(led3, LOW);
          Serial.println(0);
        }
        if(modulos[3]==1){
        digitalWrite(led4, HIGH);
          Serial.println(1);
         }else{
          digitalWrite(led4, LOW);
          Serial.println(0);
          Serial.println(cuenta);
    }
    }
    cuenta++;  
    Serial.println(cuenta);
  }
  ultimo_estado=boton_estado;

}
  