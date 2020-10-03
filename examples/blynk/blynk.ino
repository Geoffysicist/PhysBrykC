#include <physbryk.h>

PhysBryk thisBryk(LED_BUILTIN);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
}

// the loop function runs over and over again forever
void loop() {
  thisBryk.blynk();
}
