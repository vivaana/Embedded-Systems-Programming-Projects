const int IR = 7;
const int LEDG = 2;
const int LEDR = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(IR, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  Serial.begin(9600); // Explanation later
}

void loop() {
  // put your main code here, to run repeatedly:
  int IR_Value = digitalRead(IR); // Digitally reads the sensor
  Serial.print(IR_Value); // Prints the value it reads to the serial monitor
  Serial.println();

  if (IR_Value == 1){
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    delay(500);

  } else{
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    delay(500);
  }
}