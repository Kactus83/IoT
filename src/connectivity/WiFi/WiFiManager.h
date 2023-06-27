#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFiNINA.h>
#include "../../config/Config.h"

class WiFiManager {
private:
  WiFiClient wifiClient;
  WiFiConfig& wifiConfig;

public:
  WiFiManager(WiFiConfig& wifiConfig);
  void connect();
  WiFiClient& getWiFiClient();
};

#endif // WIFI_MANAGER_H
