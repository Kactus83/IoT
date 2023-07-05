#ifndef RGBLEDENTITYCONFIG_H
#define RGBLEDENTITYCONFIG_H

#include "../models/EntityConfig.h"

class RGBLEDEntityConfig : public EntityConfig {
private:
  int ledPin;
  int numOfLED;

public:
  RGBLEDEntityConfig(String unique_id, int ledPin, int numOfLED) 
    : EntityConfig(unique_id, "light", "RGB LED"), ledPin(ledPin), numOfLED(numOfLED) {}  // Ajout de l'argument "RGB LED"

  int getLedPin() { return ledPin; }
  int getNumOfLED() { return numOfLED; }
};

#endif // RGBLEDENTITYCONFIG_H
