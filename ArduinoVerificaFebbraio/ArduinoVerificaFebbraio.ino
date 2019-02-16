int rosso = 12;
int verde = 10;
int bianco = 8;
int giallo = 6;
int tempo = random(1000,5001);
int tempo_ = random(1000,5001);
int cicli;

void setup() {
  //SETUP
  Serial.begin(9600);
  richiestaCicli();
  pinMode(rosso,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(bianco,OUTPUT);
  pinMode(giallo,OUTPUT);
  randomSeed(millis());

}

void loop() {
  int i = 0;
  while(i<cicli){
  accendi(rosso, giallo, tempo);

  accendi(bianco, verde, tempo_);
  i++;
  }
  setup();
}


void accendi(int led, int led_, int tempo){
  digitalWrite(led,HIGH);
  digitalWrite(led_,HIGH);
  delay(tempo);
  digitalWrite(led,LOW);
  digitalWrite(led_,LOW);
}

void richiestaCicli(){
  Serial.println("INIZIO");
  Serial.println("Quanti cicli vuoi fare?");
  while (Serial.available() == 0) {};
  cicli = Serial.readString().toInt();
}
