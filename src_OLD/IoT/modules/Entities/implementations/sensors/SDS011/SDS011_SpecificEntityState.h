#ifndef SDS011_SPECIFICENTITYSTATE_H
#define SDS011_SPECIFICENTITYSTATE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "../../../../Entities/abstract/DTO/SpecificEntityState.h"

class SDS011_SpecificEntityState : public SpecificEntityState {
public:
    SDS011_SpecificEntityState() : pm25(0), pm10(0) {}

    virtual DynamicJsonDocument getState() override {
        DynamicJsonDocument doc(1024);
        doc["pm2.5"] = pm25;
        doc["pm10"] = pm10;
        return doc;
    }

    virtual void setStateFromMQTTMessage(String message) override {
        // La logique de mise à jour de l'état à partir du message MQTT dépend de la structure du message.
        // Elle doit être ajoutée ici
    }

private:
    float pm25;
    float pm10;
};

#endif // SDS011_SPECIFICENTITYSTATE_H
