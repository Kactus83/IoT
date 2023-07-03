#ifndef MQTT_CONFIG_H
#define MQTT_CONFIG_H

class MQTTConfig {
public:
    MQTTConfig(const char* server, int port, const char* username, const char* password, int max_Topic)
        : SERVER(server), PORT(port), USERNAME(username), PASSWORD(password), MAX_TOPIC(max_Topic) {}
    const char* getServer() { return SERVER; }
    int getPort() { return PORT; }
    const char* getUsername() { return USERNAME; }
    const char* getPassword() { return PASSWORD; }
    int getMaxTopic() { return MAX_TOPIC; }

private:
    const char* SERVER;
    int PORT;
    const char* USERNAME;
    const char* PASSWORD;
    int MAX_TOPIC;
};

#endif // MQTT_CONFIG_H
