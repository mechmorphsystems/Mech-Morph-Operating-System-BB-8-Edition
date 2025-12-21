#pragma once

#include <Arduino.h>
#include "../Config.h"
#include "EspNow/Receiver.h"
#include "EspNow/Transmitter.h"
#include "Light/Eye.h"
#include "Light/LargeLogic.h"
#include "Light/SmallLogic.h"
#include "Light/Holoprojector.h"
#include "Light/Psi.h"
#include "Inputs.h"

class DomeLogic
{
    public:
        void init(uint8_t remoteAddress[6]);
        void run();
    private:
        Receiver receiver;
        Transmitter transmitter;
        Eye eye;
        LargeLogic largeLogic;
        SmallLogic smallLogic;
        Holoprojector holoprojector;
        Psi psi;
        Inputs inputs;
        uint32_t timer;
        uint32_t sendTimer;
        bool needSend = false;
};