#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

class WiFiConfig {
public:
    WiFiConfig(const char* ssid, const char* password) : SSID(ssid), PASSWORD(password) {}
    const char* getSSID() { return SSID; }
    const char* getPassword() { return PASSWORD; }

private:
    const char* SSID;
    const char* PASSWORD;
};

#endif // WIFI_CONFIG_H
