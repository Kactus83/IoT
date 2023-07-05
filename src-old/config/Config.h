#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include "./WiFi/WiFiConfig.h"
#include "./MQTT/MQTTConfig.h"
#include "./Device/DeviceConfig.h"

class Config {
public:
  static Config& getInstance() {
    static Config instance;
    return instance;
  }

  WiFiConfig& getWifiConfig() {
    return wifiConfig;
  }

  MQTTConfig& getMqttConfig() {
    return mqttConfig;
  }

  DeviceConfig& getDeviceConfig() {
    return deviceConfig;
  }

private:
  // MQTT parameters
  const char* MQTT_SERVER = "192.168.1.98";
  const int MQTT_PORT = 1883;
  const char* MQTT_USERNAME = "MQTT";
  const char* MQTT_PASSWORD = "MQTT_mqtt_2023!";
  int MAX_TOPIC = 10;

  // WiFi parameters
  const char* WIFI_SSID = "24ghz";
  const char* WIFI_PASSWORD = "PsLyzNnnMBGAcS1jql4H";

  // Device parameters
  const char* INTEGRATION_NAME = "flo_perso";
  const char* DEVICE_NAME = "test_device";
  const char* UNIQUE_ID = "unic_id";

  WiFiConfig wifiConfig = WiFiConfig(WIFI_SSID, WIFI_PASSWORD);
  MQTTConfig mqttConfig = MQTTConfig(MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD, MAX_TOPIC);
  DeviceConfig deviceConfig = DeviceConfig(INTEGRATION_NAME, DEVICE_NAME, UNIQUE_ID);

  // Private constructor to prevent instancing.
  Config() {}
  
  // Delete the methods we don't want (these are necessary to maintain a singleton)
  Config(Config const&) = delete;
  void operator=(Config const&) = delete;
};

#endif // CONFIG_H
