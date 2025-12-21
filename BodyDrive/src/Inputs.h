#pragma once

#include <Arduino.h>
#include "../Config.h"

class Inputs
{
    public:
        int16_t getSideToSiePotValue();
        void readBatteryVoltage();
        float getBatteryVoltage();
    private:
        float batteryVoltage = 0;
        uint32_t lastBatteryUpdate;
};