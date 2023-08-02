#include <Servo.h>

Servo servo;
const int servoPin = 4;
const int Pin = 5;
bool moveRight = true; // Flag to determine the movement direction
bool OpeningSignal = false;
bool ClosingSignal = false;
bool IsOpen = false;
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
  OpeningSignal = true;
  } else {
    ClosingSignal = true;
    }

if (OpeningSignal == true & IsOpen == false) {
      //  servo.write(50);
       Serial.println("Opening");
       delay(500); 
       OpeningSignal = false;
       IsOpen = true;      
}

if (ClosingSignal == true & IsOpen == true) {
      //  servo.write(50);
       Serial.println("Closing");
       delay(500); 
       ClosingSignal = false;
       IsOpen = false;       
}

}