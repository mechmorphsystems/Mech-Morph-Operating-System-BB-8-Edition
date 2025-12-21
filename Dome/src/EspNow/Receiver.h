#pragma once

#include <Arduino.h>
#include <esp_now.h>
#include "../../Config.h"

class Receiver
{
    public:
        void init();
        int16_t getDomeLightMode();
        float getBodyBattery();
};
