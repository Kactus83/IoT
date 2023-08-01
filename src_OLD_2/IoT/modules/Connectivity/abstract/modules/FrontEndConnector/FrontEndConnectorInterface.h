#ifndef FRONT_END_CONNECTOR_INTERFACE_H
#define FRONT_END_CONNECTOR_INTERFACE_H

class FrontEndConnectorInterface {
public:
    virtual ~FrontEndConnectorInterface() {}

    virtual void connect() = 0;
    virtual bool isConnected() = 0;
    virtual void registerEntity() = 0;
    virtual void sendMessage(const char* topic, const char* message) = 0;
};

#endif // FRONT_END_CONNECTOR_INTERFACE_H