#ifndef RGBLEDENTITY_H
#define RGBLEDENTITY_H

#include <Adafruit_NeoPixel.h>
#include "../models/Entity.h"
#include "RGBLEDEntityConfig.h"
#include "RGBLEDEntityState.h"

class RGBLEDEntity : public Entity {
private:
  RGBLEDEntityConfig ledEntityConfig;
  RGBLEDEntityState ledEntityState;
  Adafruit_NeoPixel strip; 

public:
  RGBLEDEntity(String unique_id, int ledPin, int numOfLED, ConnectivityManager& connectivityManager);

  void setupEntity() override;
  void process() override;
};

#endif // RGBLEDENTITY_H
