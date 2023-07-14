#ifndef WIFIMANAGERINTERFACE_H
#define WIFIMANAGERINTERFACE_H

#include <Arduino.h>

class WiFiManagerInterface {
public:
    virtual ~WiFiManagerInterface() {}
    virtual void connect() = 0;
    virtual bool isConnected() = 0;
    virtual void* getClient() = 0;
};

#endif
