#include "MQTTManager.h"
#include "../entities/RGB_LED/RGB_LED_Info.h"

MQTTManager* globalMQTTManager; // This is needed to bridge the callback

void globalMQTTCallback(char* topic, byte* payload, unsigned int length) {
  globalMQTTManager->callback(topic, payload, length);
}

MQTTManager::MQTTManager(WiFiClient& wifiClient, MessageHandler& messageHandler)
  : wifiClient(wifiClient), messageHandler(messageHandler), mqttClient(wifiClient), ledInfo() {
    globalMQTTManager = this;
    mqttClient.setCallback(globalMQTTCallback);
}

void MQTTManager::callback(char* topic, byte* payload, unsigned int length) {
  // Pass the message to the MessageHandler
  messageHandler.handleMessage(topic, payload, length);
}

void MQTTManager::begin() {
  mqttClient.setServer(MQTTConfig::SERVER, MQTTConfig::PORT);
  if (!mqttClient.connected()) {
    if (mqttClient.connect("ESP8266Client", MQTTConfig::USERNAME, MQTTConfig::PASSWORD)) {
      Serial.println("connected");
      mqttClient.subscribe(MQTTConfig::getSetTopic(ledInfo.getUniqueID()).c_str());
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void MQTTManager::update() {
  if (!mqttClient.connected()) {
    begin();
  } else {
    mqttClient.loop();
    sendState();  
  }
}

void MQTTManager::registerEntity(const char* payload) {
  if (mqttClient.connected()) {
    mqttClient.publish(MQTTConfig::getDiscoveryTopic().c_str(), payload, true);
  } else {
    Serial.println("Failed to publish entity information. MQTT client is not connected.");
  }
}

void MQTTManager::sendState() {
  if (messageHandler.stateChanged) {
    RGB_LED_State lastState = messageHandler.getLastState();
    String stateMessage = lastState.getJSONMessage();

    if (stateMessage.length() > 0) {
      const char* topic = MQTTConfig::getGetTopic(ledInfo.getUniqueID()).c_str();
      const char* payload = stateMessage.c_str();
      if (mqttClient.connected()) {
        mqttClient.publish(topic, payload, true);
        messageHandler.stateChanged = false;  // Reset the flag
      } else {
        Serial.println("Failed to publish state. MQTT client is not connected.");
      }
      messageHandler.clearLastState();  
    }
  }
}
