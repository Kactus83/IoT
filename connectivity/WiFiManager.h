#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFiNINA.h>
#include "../config/WiFiConfig.h"

class WiFiManager {
private:
  WiFiClient wifiClient;
  const char* ssid;
  const char* password;

public:
  WiFiManager();
  void connect();
  WiFiClient& getWiFiClient();
};

#endif
