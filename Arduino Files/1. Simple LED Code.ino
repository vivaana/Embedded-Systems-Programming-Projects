// C++ code
//

const int LED = 13;

void setup(){
  pinMode(LED,OUTPUT);
}

void loop()
{
  digitalWrite(LED,HIGH);
  //writing digitally that the pin is on
  delay(1000);
  //gives rest of 1000 ms - 1 sec
  digitalWrite(LED,LOW);
  //writing digitally that the pin is off
  delay(1000);
  //gives rest of 1000 ms - 1 sec
}