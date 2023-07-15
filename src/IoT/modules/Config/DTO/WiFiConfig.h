#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include <Arduino.h>

struct WiFiConfig {
    const char* SSID;
    const char* PASSWORD;
};

#endif // WIFI_CONFIG_H
