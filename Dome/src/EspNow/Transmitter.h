#pragma once

#include <Arduino.h>
#include <esp_now.h>
#include "../../Config.h"

class Transmitter
{
    public:
        void init(uint8_t remoteAddress[6]);
        void send();
        void setBodyBattery(float bodyBattery);
        void setDomeBattery(float domeBattery);
    private:
        uint8_t remoteAddress[6];
};