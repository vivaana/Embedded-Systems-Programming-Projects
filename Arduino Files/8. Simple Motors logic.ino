const int m1a = 2;
const int m1b = 3;
const int m2a = 4;
const int m2b = 5;


void setup() {
  // put your setup code here, to run once:
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
  delay(1000);
}
