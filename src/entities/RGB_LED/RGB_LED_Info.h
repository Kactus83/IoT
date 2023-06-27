#ifndef RGB_LED_INFO_H
#define RGB_LED_INFO_H

#include <ArduinoJson.h>

class RGB_LED_Info {
private:
  const String unique_id = "my_light_unique_id";
  const char* name = "test_light";
  const char* type = "light";
  const char* discovery_topic = "flo_perso/discovery";
  const int pin = 6; 
  const int numberOfLED = 145; 

public:
  String getDiscoveryMessage();
  int getPin() const { return pin; } 
  int getNumberOfLED() const { return numberOfLED; } 
  String getUniqueID() const { return unique_id; }
};

#endif
