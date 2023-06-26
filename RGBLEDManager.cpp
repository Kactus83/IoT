#include "RGBLEDManager.h"

void RGBLEDManager::begin() {
  strip.begin(); 
  strip.setBrightness(255);
  strip.show(); 
}

void RGBLEDManager::update() {
  if (messageHandler.hasNewMessage()) {  
    state.setFromJSONMessage(messageHandler.getLastMessage());
    Serial.println("Received MQTT message: " + messageHandler.getLastMessage());
    Serial.println("Updated LED state: " + state.getJSONMessage());
    updatePhysicalLED();  // Update the physical state of the LED
    updateStateAndHandler();  // Update the state and store it in the message handler
    messageHandler.clearLastMessage();  // Clear the last message after processing
  }
}

void RGBLEDManager::updatePhysicalLED() {
  uint32_t rgbColor;
  int r, g, b;

  if (state.isOn()) {
    // Convert HS color to RGB color
    hsvToRgb(state.getHue(), state.getSaturation(), 255, r, g, b);

    // Set LED color and brightness
    rgbColor = strip.Color(r, g, b);
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, rgbColor);
    }
    strip.setBrightness(state.getBrightness());
  } else {
    // Turn off the LEDs
    rgbColor = strip.Color(0, 0, 0);
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, rgbColor);
    }
  }

  // Update the LEDs
  strip.show();
}

void RGBLEDManager::updateStateAndHandler() {
  // Only send the state if it has changed
  if (state.getJSONMessage() != messageHandler.getLastState().getJSONMessage()) {
    // Update the state of the LED based on the physical state
    String stateMessage = state.getJSONMessage();
    Serial.println("Current LED state: " + stateMessage);
    messageHandler.handleState(state); 
  }
}

void RGBLEDManager::hsvToRgb(int h, int s, int v, int &r, int &g, int &b) {
  h = (h % 360) * 6;
  s = s > 100 ? 100 : s < 0 ? 0 : s;
  v = v > 100 ? 100 : v < 0 ? 0 : v;
  
  int i = h / 360;
  int f = h % 60;
  int p = v * (100 - s) / 100;
  int q = v * (6000 - s*f) / 6000;
  int t = v * (6000 - s*(60 - f)) / 6000;
  
  switch (i) {
    case 0: r = v; g = t; b = p; break;
    case 1: r = q; g = v; b = p; break;
    case 2: r = p; g = v; b = t; break;
    case 3: r = p; g = q; b = v; break;
    case 4: r = t; g = p; b = v; break;
    case 5: r = v; g = p; b = q; break;
  }
  
  r = r * 255 / 100;
  g = g * 255 / 100;
  b = b * 255 / 100;
}

