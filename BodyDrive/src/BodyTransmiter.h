#pragma once

#include <Arduino.h>
#include <EasyTransfer.h>
#include "BodyTransmiterStruct.h"
#include "Receivers/BodyReceiver.h"
#include "Inputs.h"

class BodyTransmiter
{
    public:
        void init(BodyReceiver* bodyReceiver, Inputs* inputs);
        void sendData();
    private:
        EasyTransfer transmitBody;
        BodyReceiver* bodyReceiver;
        Inputs* inputs;
        bool needSend = false;
};