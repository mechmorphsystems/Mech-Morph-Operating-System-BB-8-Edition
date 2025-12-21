#pragma once

#include <Arduino.h>
#include <esp_now.h>
#include "../../Config.h"

class Transmitter
{
    public:
        void init(uint8_t remoteAddress[6]);
        void send();
        void setTopLeftXJoystick(int16_t value);
        void setTopLeftYJoystick(int16_t value);
        void setTopRightXJoystick(int16_t value);
        void setTopRightYJoystick(int16_t value);
        void setBottomLeftXJoystick(int16_t value);
        void setBottomRightXJoystick(int16_t value);
        void setSpeed(int16_t value);
        void setDirection(int16_t value);
        void setSoundBip(int16_t value);
        void setSoundMusic(int16_t value);
        void setCalibrationId(int16_t value);
        void setMotorEnable(int16_t value);
        void setDomeLightMode(int16_t value);
    private:
        uint8_t remoteAddress[6];
};