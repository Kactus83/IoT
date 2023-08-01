#ifndef GENERIC_CONNECTED_OBJECT_H
#define GENERIC_CONNECTED_OBJECT_H

#include "modules/Config/abstract/AbstractConfigsManager.h"

template<class TConfigsManager>
class GenericConnectedObject {
public:

    void setup() {
        // Common setup logic for all connected objects
        configsManager.initializeUserSettings();
    }

    void loop() {
        // Common loop logic for all connected objects
    }
protected:
    TConfigsManager configsManager;
};

#endif // GENERIC_CONNECTED_OBJECT_H
