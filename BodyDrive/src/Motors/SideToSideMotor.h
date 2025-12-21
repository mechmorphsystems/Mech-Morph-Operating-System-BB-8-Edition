#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <GyverMotor.h>
#include "GyverPID.h"

class SideToSideMotor
{
    public:
        void init();
        void run();
        void setJoystickValue(int16_t val, int8_t direction);
        void setRoll(float roll);
        void setRollOffset(float rollOffset);
        void setSideTosidePot(int sideToSidePot);
        void setSideTosidePotOffset(int sideToSidePotOffset);
    private:
        GMotor motor = GMotor(DRIVER2WIRE, SIDE_TO_SIDE_MOTOR_R_PWM_PIN, SIDE_TO_SIDE_MOTOR_L_PWM_PIN);
        GyverPID sideTosideTiltPid = GyverPID(SIDE_TO_SIDE_TILT_PID_KP, SIDE_TO_SIDE_TILT_PID_Ki, SIDE_TO_SIDE_TILT_PID_KD, SIDE_TO_SIDE_TILT_PID_DT);
        GyverPID sideTosideStabilityPid = GyverPID(SIDE_TO_SIDE_STABILITY_PID_KP, SIDE_TO_SIDE_STABILITY_PID_Ki, SIDE_TO_SIDE_STABILITY_PID_KD, SIDE_TO_SIDE_STABILITY_PID_DT);
        int16_t joystickValue;
        float roll;
        float rollOffset;
        int sideToSidePot;
        int sideToSidePotOffset;
        float tiltSetpoint = 0;
        float tiltInput = 0;
        float tiltResult = 0;
        float stabilitySetpoint = 0;
        float stabilityInput = 0;
        float stabilityResult = 0;
        void calcultaTiltSetpoint();
        void calcultaTiltInput();
        void calcultaStabilitySetpoint();
        void calcultaStabilityInput();
};