#include <Servo.h>

Servo servo;
const int interruptPin = 2; 
const int servoPin = 4
int servoPosition = 0;

void interruptFunction() {
  // Increment servo position
  servoPosition += 10; // Change this according to your requirements
  if (servoPosition > 180) {
    servoPosition = 180;
  }
  servo.write(servoPosition);
}


void setup()
{
  Serial.begin(9600)
  
  servo.attach(servoPin); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, RISING);
}
void loop()
{

}