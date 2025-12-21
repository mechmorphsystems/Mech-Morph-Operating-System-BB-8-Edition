#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <GyverMotor.h>

class DomeMotor
{
    public:
        void init();
        void run(int val);
    private:
        GMotor motor = GMotor(DRIVER2WIRE, DOME_MOTOR_IN3_PIN, DOME_MOTOR_IN4_PIN);
};