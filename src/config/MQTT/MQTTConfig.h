#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H

class MQTTConfig {
public:
    MQTTConfig(const char* server, int port, const char* username, const char* password)
        : SERVER(server), PORT(port), USERNAME(username), PASSWORD(password) {}
    const char* getServer() { return SERVER; }
    int getPort() { return PORT; }
    const char* getUsername() { return USERNAME; }
    const char* getPassword() { return PASSWORD; }

private:
    const char* SERVER;
    int PORT;
    const char* USERNAME;
    const char* PASSWORD;
};

#endif // MQTT_CONFIG_H
