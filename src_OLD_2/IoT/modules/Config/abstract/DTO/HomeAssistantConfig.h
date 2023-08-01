#ifndef HOME_ASSISTANT_CONFIG_H
#define HOME_ASSISTANT_CONFIG_H

struct HomeAssistantConfig {
    const char* SERVER;
    int PORT;
    const char* USERNAME;
    const char* PASSWORD;

    bool isValid() const {
        return SERVER != nullptr && USERNAME != nullptr && PASSWORD != nullptr;
    }
};

#endif // HOME_ASSISTANT_CONFIG_H
