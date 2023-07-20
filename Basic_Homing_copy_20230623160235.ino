/* Include necessary libraries */
#include <ZaberAscii.h>

ZaberShield shield(ZABERSHIELD_ADDRESS_AA);
ZaberAscii za(shield);

const int pin = 2;
const int LEDpin = 4;
int lastState = LOW;

 
void setup() {
  Serial.begin(9600);
  shield.begin(115200); /* Initialize baudrate to 115200, typical for Zaber ASCII devices */

  MoveBackwards();

  pinMode(pin, INPUT);
  pinMode(LEDpin, OUTPUT);
}
 
void loop() {

int currentState = digitalRead(pin);

if (lastState == LOW & currentState == HIGH) {
   MoveForward();

   digitalWrite(LEDpin, HIGH);
   delay(500);
   digitalWrite(LEDpin, LOW);

   MoveBackwards();
   
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

    Serial.println("Moving forward");
}

void MoveBackwards (){
    za.send(1, "move abs", 1);
    za.receive();
    za.pollUntilIdle(1);
}

