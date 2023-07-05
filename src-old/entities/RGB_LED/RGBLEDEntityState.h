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

  void RGBLEDEntityState::populateJson(JsonObject& json) override {
    EntityState::populateJson(json);
    json["brightness"] = brightness;
    json["hs_color_1"] = hs_color_1;
    json["hs_color_2"] = hs_color_2;
    json["state"] = state;
    json["mode"] = mode;

    // DEBUG: Ajout d'une déclaration de débogage pour voir les valeurs qui sont ajoutées au JSON.
    Serial.println("Populating JSON: brightness=" + String(brightness)
      + ", hs_color_1=" + String(hs_color_1)
      + ", hs_color_2=" + String(hs_color_2)
      + ", state=" + state
      + ", mode=" + String(mode));
  }
  
  void updateFromJson(const JsonObject& json) override {
    Serial.println("UpdateFromJson called");
    EntityState::updateFromJson(json);
    if(json.containsKey("brightness")) {
      brightness = json["brightness"];
      Serial.println("Updated brightness: " + String(brightness));
    }
    if(json.containsKey("hs_color_1")) {
      hs_color_1 = json["hs_color_1"];
      Serial.println("Updated hs_color_1: " + String(hs_color_1));
    }
    if(json.containsKey("hs_color")) {
      JsonArray hs_color = json["hs_color"];
      hs_color_1 = hs_color[0];
      hs_color_2 = hs_color[1];
      Serial.println("Updated hs_color_1: " + String(hs_color_1));
      Serial.println("Updated hs_color_2: " + String(hs_color_2));
    }
    if(json.containsKey("state")) {
      state = json["state"].as<String>();
      Serial.println("Updated state: " + state);
    }
    if(json.containsKey("mode")) {
      mode = json["mode"];
      Serial.println("Updated mode: " + String(mode));
    }
    Serial.println("State Updated.");
    setHasBeenUpdated(true);
  }

  int getBrightness() { return brightness; }
  double getHsColor1() { return hs_color_1; }
  double getHsColor2() { return hs_color_2; }
  String getState() { return state; }
  int getMode() { return mode; }
};

#endif // RGBLEDENTITYSTATE_H
