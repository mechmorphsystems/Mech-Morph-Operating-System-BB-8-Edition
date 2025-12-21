#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <GyverMotor.h>

class FlywheelSpinMotor
{
    public:
        void init();
        void run(int val);
    private:
        GMotor motor = GMotor(DRIVER2WIRE, FLYWHEEL_SPIN_MOTOR_R_PWM_PIN, FLYWHEEL_SPIN_MOTOR_L_PWM_PIN);
};

