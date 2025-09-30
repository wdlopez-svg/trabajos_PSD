const int led = 13;     
const int boton = 2;  

int led_estado = LOW;       
int boton_ultimo_estado = HIGH;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT); 
}

void loop() {
  int boton_estado = digitalRead(boton);

  
  if (boton_estado == LOW && boton_ultimo_estado == HIGH) {
    led_estado = !led_estado;
    digitalWrite(led, led_estado);
  }

  boton_ultimo_estado = boton_estado;
}
