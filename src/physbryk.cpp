/*
	PhysBryk

	Small robust microcontroller and sensors for conducting high school physics investigations
    Based on the Adafruit Feather nRF52840 Sense utilising the Arduino Science Journal.

	The circuit:
	* list the components attached to each input
	* list the components attached to each output

	Created 20201002
	@author Geoffysicist
	@version 0.0.1
	License CC0 1.0 Universal
*/

#include "Arduino.h"
#include <physbryk.h>


PhysBryk::PhysBryk(int pin)
{
	pinMode(pin, OUTPUT);
	_pin = pin;
}

bool PhysBryk::begin() {
	if(!_apds9960.begin()) return false;
	_apds9960.enableProximity(true);
	return true;
}

void PhysBryk::end() {
	// _apds9960.end();
}

void PhysBryk::blynk() {
	digitalWrite(_pin, HIGH);   // turn the LED on (HIGH is the voltage level)
	delay(500);
	blynkPrivate();
}

void PhysBryk::blynkPrivate() {
	digitalWrite(_pin, LOW);   // turn the LED on (HIGH is the voltage level)
	delay(500);
}

float PhysBryk::proximityRead() {
	float proximity = _apds9960.readProximity();
	proximity = proximity * 100 / 255;
	return proximity;
}