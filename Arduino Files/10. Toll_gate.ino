#include <Servo.h>
const int Servop = 13;
Servo smotor;
const int Trig = 9;
const int Echo = 8;
long Duration;
int Distance;


void setup() {
  // put your setup code here, to run once:
  smotor.attach(Servop);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Trig, LOW);
  delay(20);
  digitalWrite(Trig, HIGH);
  delay(100);
  digitalWrite(Trig, LOW);
  Duration = pulseIn(Echo, HIGH);   //measures time to make ECHO high
  Distance = Duration * 0.034 / 2;  // Formula to find it twice / 2 - velocity of sound
  Serial.print("Distance");
  Serial.println(Distance);
  if (Distance < 5) {
    smotor.write(180);
    delay(1000);
  } else {
    smotor.write(90);
  }
}