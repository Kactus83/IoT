#ifndef RGBLEDENTITYSTATE_H
#define RGBLEDENTITYSTATE_H

#include "../models/EntityState.h"

class RGBLEDEntityState : public EntityState {
private:
  int brightness;
  double hs_color_1;
  double hs_color_2;
  String state;
  int mode;

public:
  RGBLEDEntityState() 
    : EntityState(true, false), brightness(0), hs_color_1(0.0), hs_color_2(0.0), state("OFF"), mode(0) {}

  void populateJson(JsonObject& json) override {
    EntityState::populateJson(json);
    json["brightness"] = brightness;
    json["hs_color_1"] = hs_color_1;
    json["hs_color_2"] = hs_color_2;
    json["state"] = state;
    json["mode"] = mode;
  }

  
  void updateFromJson(const JsonObject& json) {
    EntityState::updateFromJson(json);
    if(json.containsKey("brightness")) {
      brightness = json["brightness"];
    }
    if(json.containsKey("hs_color_1")) {
      hs_color_1 = json["hs_color_1"];
    }
    if(json.containsKey("hs_color_2")) {
      hs_color_2 = json["hs_color_2"];
    }
    if(json.containsKey("state")) {
      state = json["state"].as<String>();
    }
    if(json.containsKey("mode")) {
      mode = json["mode"];
    }
    setHasBeenUpdated(true);
  }

  int getBrightness() { return brightness; }
  double getHsColor1() { return hs_color_1; }
  double getHsColor2() { return hs_color_2; }
  String getState() { return state; }
  int getMode() { return mode; }
};

#endif // RGBLEDENTITYSTATE_H