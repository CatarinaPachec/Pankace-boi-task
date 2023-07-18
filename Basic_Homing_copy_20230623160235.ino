/* Include necessary libraries */
#include <ZaberAscii.h>

ZaberShield shield(ZABERSHIELD_ADDRESS_AA);
ZaberAscii za(shield);

boolean ShouldMove = true;
 
void setup() {
  Serial.begin(9600);

  /* Initialize baudrate to 115200, typical for Zaber ASCII devices */
  shield.begin(115200);

  /* Issue a command for initial position */
  za.send(1, "move abs", 1);
  /* Always read the reply even if you don't check it for errors. */
  za.receive();
  /* Wait for the move command to finish moving. */
  za.pollUntilIdle(1);
}
 
void loop() {
 /* Issue a position */
  if (ShouldMove==true) {
    Serial.println("Movement Start");

    za.send(1, "move abs", 533333);
    za.receive();
    /* Wait for the move command to finish moving. */
    za.pollUntilIdle(1);

    Serial.println("Pause");
    delay (500);

    /* Issue a position */
    za.send(1, "move abs", 1);
    za.receive();
    za.pollUntilIdle(1);

    Serial.println("Movement End");

    ShouldMove = false;
  }
}

