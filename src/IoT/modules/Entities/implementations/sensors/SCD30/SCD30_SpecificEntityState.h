#ifndef SCD30_SPECIFICENTITYSTATE_H
#define SCD30_SPECIFICENTITYSTATE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "../../../../Entities/abstract/DTO/SpecificEntityState.h"

class SCD30_SpecificEntityState : public SpecificEntityState {
public:
    SCD30_SpecificEntityState() : co2(0), temperature(0), humidity(0) {}

    virtual DynamicJsonDocument getState() override {
        DynamicJsonDocument doc(1024);
        doc["co2"] = co2;
        doc["temperature"] = temperature;
        doc["humidity"] = humidity;
        return doc;
    }

    virtual void setStateFromMQTTMessage(String message) override {
        // La logique de mise à jour de l'état à partir du message MQTT dépend de la structure du message.
        // Elle doit être ajoutée ici
    }

private:
    int co2;
    float temperature;
    float humidity;
};

#endif // SCD30_SPECIFICENTITYSTATE_H
