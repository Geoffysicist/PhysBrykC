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

class PhysBryk
{
  public:
    PhysBryk(int pin);
    void doSomethingPublic();
  private:
	int _pin;
    void doSomethingPrivate();
};

#endif