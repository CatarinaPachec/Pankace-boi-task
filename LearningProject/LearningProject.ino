#include <Servo.h>

Servo servo;
const int servoPin = 4;
const int Pin = 5;
bool moveRight = true; // Flag to determine the movement direction
bool movesignal = false;
bool signal = LOW; 

void setup() {
  Serial.begin(9600);
  pinMode(Pin, INPUT);

  // servo.attach(servoPin);
  // servo.write(0);
}

void loop() {
int signal = digitalRead(Pin);
// Serial.println(signal);

if (signal == HIGH) {
  movesignal = true;
  }

if (movesignal == true) {
    if (moveRight) {
      //  servo.write(50);
       Serial.println("move right");
       delay(1000); 
       moveRight = !moveRight;
     } else {
      //  servo.write(0);
       Serial.println("move left");
       moveRight = !moveRight;
       movesignal = false;
       Serial.println("move stop");
    }

  }

}

