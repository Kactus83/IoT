#include "./connectivity/WiFiManager.h"
#include "./connectivity/MQTTManager.h"
#include "./messages/MessageHandler.h"
#include "./entities/RGB_LED/RGB_LED_Info.h"
#include "./entities/RGB_LED/RGBLEDManager.h" 

WiFiManager wifiManager;
MessageHandler messageHandler;
MQTTManager mqttManager(wifiManager.getWiFiClient(), messageHandler);
RGB_LED_Info rgbLedInfo; 
RGBLEDManager ledManager(rgbLedInfo, messageHandler);

void setup() {
  Serial.begin(9600);
  wifiManager.connect();
  mqttManager.begin();
  ledManager.begin();

  // Get the discovery message and register the entity
  String discoveryMessage = rgbLedInfo.getDiscoveryMessage();
  mqttManager.registerEntity(discoveryMessage.c_str());
}

void loop() {
  mqttManager.update();
  ledManager.update();
}
