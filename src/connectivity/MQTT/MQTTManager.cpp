#include "MQTTManager.h"

MQTTManager* MQTTManager::instance = NULL;

MQTTManager::MQTTManager(WiFiClient& wifiClient, MQTTConfig& mqttConfig, MessageHandler* messageHandler)
  : wifiClient(wifiClient), mqttClient(wifiClient), mqttConfig(mqttConfig), messageHandler(messageHandler) {
  instance = this;
  mqttClient.setCallback(MQTTManager::staticCallback);
}

void MQTTManager::staticCallback(char* topic, byte* payload, unsigned int length) {
  // call the non-static callback using the instance pointer
  if (instance) {
    instance->nonStaticCallback(topic, payload, length);
  }
}

void MQTTManager::nonStaticCallback(char* topic, byte* payload, unsigned int length) {
  if (messageHandler) {
    messageHandler->handleMessage(topic, payload, length);
  }
}

void MQTTManager::begin() {
  mqttClient.setServer(mqttConfig.getServer(), mqttConfig.getPort());
  if (!mqttClient.connected()) {
    if (mqttClient.connect("ESP8266Client", mqttConfig.getUsername(), mqttConfig.getPassword())) {
      Serial.println("connected");
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
  }
}

void MQTTManager::sendMQTTMessage(const char* topic, const char* payload) {
  if (mqttClient.connected()) {
    mqttClient.publish(topic, payload, true);
  } else {
    Serial.println("Failed to send MQTT message. MQTT client is not connected.");
  }
}

void MQTTManager::subscribeToTopic(const char* topic) {
  if (mqttClient.connected()) {
    mqttClient.subscribe(topic);
  } else {
    Serial.println("Failed to subscribe to MQTT topic. MQTT client is not connected.");
  }
}
