int intensidad=0;
bool aumento_disminucion=true;
int led=13;


void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(3), velocidadMenos, RISING);
}

void loop() {
  if (aumento_disminucion && intensidad<256){
    intensidad++;
  }
  if(!aumento_disminucion && intensidad>0){
    intensidad--;
  }
  delay(50);
  analogWrite(led, intensidad);
  Serial.println(intensidad);
}

void velocidadMenos()
{
aumento_disminucion=!aumento_disminucion;
  }
