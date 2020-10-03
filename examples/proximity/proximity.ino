#include <physbryk.h>
#include <Arduino_APDS9960.h>

PhysBryk thisBryk(LED_BUILTIN);

// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    Serial.begin(115200);
    // while (!Serial) delay(10);
    Serial.println("PhysBryk Proximity Demo");
    if (thisBryk.begin()) Serial.println("the Bryk is ready");
    // else Serial.println("the Bryk is stuffed")
  
}

// the loop function runs over and over again forever
void loop() {
  
}
