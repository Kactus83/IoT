#ifndef MICS_4514_SPECIFICENTITYSTATE_H
#define MICS_4514_SPECIFICENTITYSTATE_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "../../../../Entities/abstract/DTO/SpecificEntityState.h"

class MICS_4514_SpecificEntityState : public SpecificEntityState {
public:
    MICS_4514_SpecificEntityState() : no2(0), co(0) {}

    virtual DynamicJsonDocument getState() override {
        DynamicJsonDocument doc(1024);
        doc["no2"] = no2;
        doc["co"] = co;
        return doc;
    }

    virtual void setStateFromMQTTMessage(String message) override {
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, message);
        if (doc.containsKey("no2")) {
            int newNo2 = doc["no2"];
            if(no2 != newNo2) {
                no2 = newNo2;
                stateChanged = true;
            }
        }
        if (doc.containsKey("co")) {
            int newCo = doc["co"];
            if(co != newCo) {
                co = newCo;
                stateChanged = true;
            }
        }
    }

private:
    int no2;
    int co;
};

#endif // MICS_4514_SPECIFICENTITYSTATE_H
