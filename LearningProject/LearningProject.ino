#include <Servo.h>

Servo servo;
const int servoPin = 4;
const int Pin = 5;
bool moveRight = true; // Flag to determine the movement direction

void setup() {
  pinMode(Pin, INPUT);

  servo.attach(servoPin);
  servo.write(0);
}

void loop() {
  if (moveRight) {
    servo.write(50);
  } else {
    servo.write(0);
  }
  
  delay(1000); // Adjust the delay time to change the speed of movement
  
  moveRight = !moveRight; // Toggle the flag for the next iteration
}

