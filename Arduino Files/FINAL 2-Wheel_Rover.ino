#include <Servo.h>
//
const int Servop = 10;
Servo myservo;
const int Trig = 9;
const int Echo = 8;
long Duration;
int Distance;
int DistRight = 0;
int DistLeft = 0;

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);

  myservo.attach(Servop);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  Serial.begin(9600);
}

void forwards(){
  //Controlling speed (0 = off and 255 = max speed):
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void backwards(){
  //Controlling speed (0 = off and 255 = max speed):
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void stop(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void turnRight(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}

void turnLeft(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


void measure_distance(){
  digitalWrite(Trig, LOW);
  delay(20);
  digitalWrite(Trig, HIGH);
  delay(100);
  digitalWrite(Trig, LOW);
  Duration = pulseIn(Echo, HIGH);   //measures time to make ECHO high
  Distance = Duration * 0.034 / 2;  // Formula to find it twice / 2 - velocity of sound
  Serial.print("Distance");
  Serial.println(Distance);
}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    measure_distance();
    DistRight = Distance;
    delay(100);
    myservo.write(115); 
    return Distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    measure_distance();
    DistLeft = Distance;
    delay(100);
    myservo.write(115); 
    return Distance;
    delay(100);
}

void loop() {
  myservo.write(90);
  if (Distance <= 35){
    stop();
    delay(100);
    backwards();
    delay(300);
    stop();
    delay(200);
    lookRight();
    delay(200);
    lookLeft();
    delay(200);

    if (DistRight >= DistLeft){
      turnRight();
      stop();
    } else{
      turnLeft();
      stop();
    }
  }else{
    forwards();
  }
}