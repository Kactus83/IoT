#ifndef RGBLEDENTITYCONFIG_H
#define RGBLEDENTITYCONFIG_H

#include "../models/EntityConfig.h"

class RGBLEDEntityConfig : public EntityConfig {
private:
  int ledPin;
  int numOfLED;

public:
  RGBLEDEntityConfig(String unique_id, int ledPin, int numOfLED) 
    : EntityConfig(unique_id, "light"), ledPin(ledPin), numOfLED(numOfLED) {}

  int getLedPin() { return ledPin; }
  int getNumOfLED() { return numOfLED; }
};

#endif // RGBLEDENTITYCONFIG_H
