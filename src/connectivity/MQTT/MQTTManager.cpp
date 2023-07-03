#include "MQTTManager.h"

MQTTManager* MQTTManager::instance = NULL;

MQTTManager::MQTTManager(WiFiClient& wifiClient, MQTTConfig& mqttConfig, MessageHandler* messageHandler)
  : wifiClient(wifiClient), mqttClient(wifiClient), mqttConfig(mqttConfig), messageHandler(messageHandler) {
  instance = this;
  mqttClient.setCallback(MQTTManager::staticCallback);
  subscribedTopics = new String[mqttConfig.getMaxTopic()];  // Initialize subscribedTopics with the maximum size from the configuration
}

MQTTManager::~MQTTManager() {
  delete[] subscribedTopics;  // Delete the array when the object is destroyed
}

void MQTTManager::staticCallback(char* topic, byte* payload, unsigned int length) {
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
      for (int i = 0; i < numTopics; i++) {
        mqttClient.subscribe(subscribedTopics[i].c_str());
      }
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
    if (payload != NULL && strlen(payload) > 0) {
      mqttClient.publish(topic, payload, true);
      Serial.println("MQTT message sent.");
      Serial.println(payload);
    } else {
      Serial.println("Failed to send MQTT message. Payload is empty.");
    }
  } else {
    Serial.println("Failed to send MQTT message. MQTT client is not connected.");
  }
}

void MQTTManager::subscribeToTopic(const char* topic) {
  if (mqttClient.connected()) {
    if (mqttClient.subscribe(topic)) {
      Serial.print("Successfully subscribed to topic: ");
      Serial.println(topic);
      if(numTopics < mqttConfig.getMaxTopic()) {
        subscribedTopics[numTopics++] = String(topic);
      }
    } else {
      Serial.print("Failed to subscribe to topic: ");
      Serial.println(topic);
    }
  } else {
    Serial.println("Failed to subscribe to MQTT topic. MQTT client is not connected.");
  }
}
