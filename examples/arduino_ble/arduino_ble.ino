#include <Arduino_APDS9960.h>

// #include <ArduinoBLE.h>
#include <bluefruit.h>

const int VERSION = 0x00000001;

#define SCIENCE_KIT_UUID(val) ("555a0002-" val "-467a-9538-01f0652c74e8")

#define DEBUG 0

BLEService                     service                    (SCIENCE_KIT_UUID("0000"));
BLEUnsignedIntCharacteristic   versionCharacteristic      (SCIENCE_KIT_UUID("0001"), BLERead);
BLEUnsignedIntCharacteristic   proximityCharacteristic    (SCIENCE_KIT_UUID("0017"), BLENotify);

// String to calculate the local and device name
String name;
unsigned long lastNotify = 0;

void printSerialMsg(const char * msg) {
  #ifdef DEBUG
  if (Serial) {
    Serial.println(msg);
  }
  #endif
}

void blinkLoop() {
  while (1) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}

void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");
  #endif

  delay(2000);

  if (!APDS.begin()) {
    printSerialMsg("Failed to initialized APDS!");
    blinkLoop();
  }

  if (!BLE.begin()) {
    printSerialMsg("Failed to initialized BLE!");
    blinkLoop();
  }

  String address = BLE.address();
  #ifdef DEBUG
  if (Serial) {
    Serial.print("address = ");
    Serial.println(address);
  }
  #endif
  address.toUpperCase();

  name = "PhysBryk - ";
  name += address[address.length() - 5];
  name += address[address.length() - 4];
  name += address[address.length() - 2];
  name += address[address.length() - 1];

  #ifdef DEBUG
  if (Serial) {
    Serial.print("name = ");
    Serial.println(name);
  }
  #endif

  BLE.setLocalName(name.c_str());
  BLE.setDeviceName(name.c_str());
  BLE.setAdvertisedService(service);

  service.addCharacteristic(versionCharacteristic);
  service.addCharacteristic(proximityCharacteristic);
  
  versionCharacteristic.setValue(VERSION);

  BLE.addService(service);
  BLE.advertise();

  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  while (BLE.connected()) {
    unsigned long now = millis();
    if (abs((long) now - (long) lastNotify) >= 100) {
      updateSubscribedCharacteristics();
      lastNotify = now;
    }
  }
}

void updateSubscribedCharacteristics() {
  if (proximityCharacteristic.subscribed() && APDS.proximityAvailable()) {
    uint32_t proximity = APDS.readProximity();
    proximityCharacteristic.writeValue(proximity);
  }
}