#include <Adafruit_NeoPixel.h>
#include "RGB_LED_Info.h"
#include "RGB_LED_State.h"
#include "../../messages/MessageHandler.h"

class RGBLEDManager {
private:
  RGB_LED_State state; // the state of the LED
  MessageHandler& messageHandler; // reference to the message handler
  RGB_LED_Info& ledInfo; // reference to the LED info
  Adafruit_NeoPixel strip; // NeoPixel strip
  void hsvToRgb(int h, int s, int v, int &r, int &g, int &b);
  void updateStateAndHandler();

public:
  RGBLEDManager(RGB_LED_Info& ledInfo, MessageHandler& messageHandler)
    : ledInfo(ledInfo), 
      messageHandler(messageHandler),
      strip(ledInfo.getNumberOfLED(), ledInfo.getPin(), NEO_GRB + NEO_KHZ800) {
  }

  void begin();
  void update();
  void updatePhysicalLED();
  RGB_LED_State& getState() { return state; }
};
