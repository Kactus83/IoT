#include "RGB_LED_State.h"

String RGB_LED_State::getJSONMessage() {
  DynamicJsonDocument doc(256);

  doc["state"] = on ? "ON" : "OFF";
  doc["brightness"] = brightness;
  doc["hs_color"][0] = hue;
  doc["hs_color"][1] = saturation;

  String output;
  serializeJson(doc, output);
  return output;
}

void RGB_LED_State::setFromJSONMessage(const String& message) {
  DynamicJsonDocument doc(256);
  deserializeJson(doc, message);

  if (doc.containsKey("state")) {
    on = doc["state"] == "ON";
  }
  if (doc.containsKey("brightness")) {
    brightness = doc["brightness"];
  }
  if (doc.containsKey("hs_color")) {
    hue = doc["hs_color"][0];
    saturation = doc["hs_color"][1];
  }
}

String RGB_LED_State::getJSONState() {
  DynamicJsonDocument doc(256);

  doc["state"] = on ? "ON" : "OFF";
  doc["brightness"] = brightness;
  doc["hs_color"][0] = hue;
  doc["hs_color"][1] = saturation;

  String output;
  serializeJson(doc, output);
  return output;
}

