#include "RGBLEDEntity.h"

RGBLEDEntity::RGBLEDEntity(String unique_id, int ledPin, int numOfLED, ConnectivityManager& connectivityManager)
  : ledEntityConfig(unique_id, ledPin, numOfLED),
    ledEntityState(),
    strip(Adafruit_NeoPixel(numOfLED, ledPin, NEO_GRB + NEO_KHZ800)),
    Entity(&ledEntityConfig, &ledEntityState, connectivityManager)
{} 

void RGBLEDEntity::setupEntity() {
  strip.begin();
  strip.show(); // Initialiser toutes les pixels à 'off'
}

void RGBLEDEntity::process() {
  if (ledEntityState.getState() == "ON") {
    // Conversion de HS vers RGB
    uint16_t hue = (uint16_t)((ledEntityState.getHsColor1() / 360.0) * 65535); // HUE conversion
    uint8_t sat = (uint8_t)((ledEntityState.getHsColor2() / 100.0) * 255); // SATURATION conversion
    uint8_t val = ledEntityState.getBrightness(); // BRIGHTNESS is on a scale of 0 to 255

    // Remplissage de la bande de LEDs avec la couleur obtenue
    for (int i = 0; i < ledEntityConfig.getNumOfLED(); ++i) {
      strip.setPixelColor(i, strip.ColorHSV(hue, sat, val));
    }
  }
  else {
    // Éteindre les LEDs
    for (int i = 0; i < ledEntityConfig.getNumOfLED(); ++i) {
      strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
  }

  // Envoi de la mise à jour à la bande de LEDs
  strip.show();
}


