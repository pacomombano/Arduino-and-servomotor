#define DOOR_SERVO1_PIN 3
//const (microsecods)
const int totalTime=20000; //total time duty cicle
const float timePerAngle=11.11; //time for high value into duty cicle that expresses 1°
const int intercept = 500; //0°, starting point

void setup() {
  pinMode(DOOR_SERVO1_PIN, OUTPUT);
}

//Opening function (+90°)
void apertura(){
  for(int cont=0;cont<=90;cont++){
    digitalWrite(DOOR_SERVO1_PIN, HIGH);
    delayMicroseconds(timePerAngle*cont+intercept);
    digitalWrite(DOOR_SERVO1_PIN, LOW);
    delayMicroseconds(totalTime-(timePerAngle*cont+intercept));
    delay(30);//Rallentatore
  }
}
//Closing function (-90°)
void chiusura(){
  digitalWrite(RELAY1_PIN, HIGH);
  for(int cont=0;cont<=90;cont++){
    digitalWrite(DOOR_SERVO1_PIN, HIGH);
    digitalWrite(DOOR_SERVO2_PIN, HIGH);
    delayMicroseconds(1000-timePerAngle*cont+intercept);
    digitalWrite(DOOR_SERVO1_PIN, LOW);
    digitalWrite(DOOR_SERVO2_PIN, LOW);
    delayMicroseconds(totalTime-(1000-timePerAngle*cont+intercept));
    delay(30);//Rallentatore
  }


void loop() {
  apertura();
  delay(5000);
  chiusura();
}
