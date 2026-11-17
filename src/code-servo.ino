#define DOOR_SERVO1_PIN 3
const int totalTime=20000; //durata totale del duty cycle
const float timePerAngle=11.11;
const int intercept = 500;

void setup() {
  pinMode(DOOR_SERVO1_PIN, OUTPUT);

}


void apertura(){
  for(int cont=0;cont<=90;cont++){
    digitalWrite(DOOR_SERVO1_PIN, HIGH);
    delayMicroseconds(timePerAngle*cont+intercept);
    digitalWrite(DOOR_SERVO1_PIN, LOW);
    delayMicroseconds(totalTime-(timePerAngle*cont+intercept));
    delay(30);//Rallentatore
  }
}



void loop() {
  apertura();
  delay(2000);

}
