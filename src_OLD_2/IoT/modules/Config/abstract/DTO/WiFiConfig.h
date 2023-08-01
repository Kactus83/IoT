#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

struct WiFiConfig {
    const char* SSID;
    const char* PASSWORD;
    
    bool isValid() const {
        return SSID != nullptr && PASSWORD != nullptr;
    }
};

#endif // WIFI_CONFIG_H
