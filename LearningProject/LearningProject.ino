#include <Servo.h>

Servo servo;
const int servoPin = 4;


void setup() {
  servo.attach(servoPin);
  servo.write(50);

}

void loop() {
  // put your main code here, to run repeatedly:

}
