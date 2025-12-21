#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <EasyTransfer.h>
#include "BodyReceiveStruct.h"

class BodyReceiver
{
    public:
        void init();
        void receiveData();
        bool isActive();
        int16_t getTopLeftXJoystickValue();
        int16_t getTopLeftYJoystickValue();
        int16_t getTopRightYJoystickValue();
        int16_t getTopRightXJoystickValue();
        int16_t getBottomLeftXJoystickValue();
        int16_t getBottomRightXJoystickValue();
        int16_t getSpeedValue();
        int16_t getDirectionValue();
        int16_t getSoundBipValue();
        int16_t getSoundMusicValue();
        int16_t getCalibrationIdValue();
        int16_t isEnabledMotor();
        int16_t getDomeLightMode();
    private:
        EasyTransfer ReceiveBody;
        bool active;
        uint32_t lastReceiveDataTime;
        void checkLastReceiveData();
};