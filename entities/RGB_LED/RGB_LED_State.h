#ifndef RGB_LED_STATE_H
#define RGB_LED_STATE_H

#include <ArduinoJson.h>

class RGB_LED_State {
private:
  bool on; // true if LED is on, false if off
  int brightness; // 0 to 255
  int hue; // 0 to 360
  int saturation; // 0 to 100

public:
  RGB_LED_State() : on(false), brightness(0), hue(0), saturation(0) {}

  bool isOn() const { return on; }
  int getBrightness() const { return brightness; }
  int getHue() const { return hue; }
  int getSaturation() const { return saturation; }

  String getJSONMessage();
  void setFromJSONMessage(const String& message);
  String getJSONState();
};

#endif // RGB_LED_STATE_H