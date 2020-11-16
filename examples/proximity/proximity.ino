#include <physbryk.h>
// #include <Arduino_APDS9960.h>
// #include <Adafruit_APDS9960.h>

PhysBryk thisBryk(LED_BUILTIN);
bool success;

// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    Serial.begin(115200);
    // while (!Serial) delay(10);
    Serial.println("PhysBryk Proximity Demo");
    if (thisBryk.begin()) success = true;
    // else Serial.println("the Bryk is stuffed")
  
}

// the loop function runs over and over again forever
void loop() {
  thisBryk.blynk();
  if (success) Serial.println(thisBryk.proximityRead());
  
}
