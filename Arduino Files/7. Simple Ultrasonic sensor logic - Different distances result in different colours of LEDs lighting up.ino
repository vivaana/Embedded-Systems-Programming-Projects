const int LEDR = 2;
const int LEDY = 3;
const int LEDG = 5;
const int Trig = 9;
const int Echo = 10;
long Duration;
int Distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDR, OUTPUT);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDG, OUTPUT);
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
  Duration = pulseIn(Echo, HIGH); //measures time to make ECHO high
  Distance = Duration*0.034/2; // Formula to find it twice / 2 - velocity of sound
  Serial.print("Distance");
  Serial.println(Distance);
  if (Distance < 5){
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDY, LOW);
    digitalWrite(LEDR, HIGH);
  } else if (Distance > 5 && Distance < 10){
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDY, HIGH);
    digitalWrite(LEDR, LOW);  
  } else if (Distance > 10){
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDY, LOW);
    digitalWrite(LEDR, LOW);
  }
}