/*
	PhysBryk

	Small robust microcontroller and sensors for conducting high school physics investigations
    Based on the Adafruit Feather nRF52840 Sense utilising the Arduino Science Journal.

	The circuit:
	* list the components attached to each input
	* list the components attached to each output

	Created 20201002
	By Geoffysicist
	License CC0 1.0 Universal
*/

#ifndef physbryk_h
#define physbryk_h

// the #include statment and code go here...
#include "Arduino.h"
// #include <Adafruit_APDS9960.h>
// #include <Arduino_APDS9960.h>


class PhysBryk
{
  public:
    PhysBryk(int pin);
	  bool begin();
	  void end();
    void blynk();
  private:
	  int _pin;
	  // Adafruit_APDS9960 _apds9960; // proximity, light, color, gesture
    void blynkPrivate();
};

#endif