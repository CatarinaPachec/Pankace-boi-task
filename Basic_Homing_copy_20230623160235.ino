/* Include necessary libraries */
#include <ZaberAscii.h>

ZaberShield shield(ZABERSHIELD_ADDRESS_AA);
ZaberAscii za(shield);

const int pin = 2;
const int Forwardpin = 4;
const int Soundpin = 5;
const int Backwardspin = 6;
int lastState = LOW;

 
void setup() {
  Serial.begin(9600);
  shield.begin(115200); /* Initialize baudrate to 115200, typical for Zaber ASCII devices */

  MoveBackwards();

  pinMode(pin, INPUT);
  pinMode(Forwardpin, OUTPUT);
  pinMode(Soundpin, OUTPUT);
  pinMode(Backwardspin, OUTPUT);
}
 
void loop() {

int currentState = digitalRead(pin);

if (lastState == LOW & currentState == HIGH) {
   RunTrial();

   lastState = HIGH;
   }
else if (currentState == LOW){
  lastState = LOW;
}

}

void MoveForward (){
    za.send(1, "move abs", 533333);
    za.receive();
    za.pollUntilIdle(1);

}

void MoveBackwards (){
    za.send(1, "move abs", 1);
    za.receive();
    za.pollUntilIdle(1);
}

void RunTrial (){
  digitalWrite(Forwardpin, HIGH);
  MoveForward();
  digitalWrite(Forwardpin, LOW);

  digitalWrite(Soundpin, HIGH);
  delay(500);
  digitalWrite(Soundpin, LOW);

  digitalWrite(Backwardspin, HIGH);
  MoveBackwards();
  digitalWrite(Backwardspin, LOW);
}

