#include "RGB_LED_Info.h"

String RGB_LED_Info::getDiscoveryMessage() {
  DynamicJsonDocument doc(1024);

  doc["type"] = type;
  doc["name"] = name;
  doc["state"] = false;
  doc["brightness"] = 255;
  doc["hs_color"][0] = 0;
  doc["hs_color"][1] = 0;
  doc["unique_id"] = unique_id;

  String output;
  serializeJson(doc, output);

  return output;
}
