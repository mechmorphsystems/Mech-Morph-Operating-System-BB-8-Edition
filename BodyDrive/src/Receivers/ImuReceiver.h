#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <EasyTransfer.h>
#include "ImuReceiveStruct.h"

class ImuReceiver
{
    public:
        void init();
        void receiveData();
        bool isActive();
        float getImuLoopValue();
        float getPitchValue();
        float getRollValue();
    private:
        EasyTransfer ReceiveImu;
        bool active = false;
        uint32_t lastReceiveDataTime;
        void checkLastReceiveData();
};