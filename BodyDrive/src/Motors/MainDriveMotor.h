#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <GyverMotor.h>
#include "GyverPID.h"

class MainDriveMotor
{
    public:
        void init();
        void run();
        void setSpeed(int speed);
        void setJoystickValue(int16_t val, int8_t direction);
        void setPitch(float pitch);
        void setPitchOffset(float pitchOffset);
        void setServoYAngle(float yAngle);
    private:
        GMotor motor = GMotor(DRIVER2WIRE, MAIN_DRIVE_MOTOR_R_PWM_PIN, MAIN_DRIVE_MOTOR_L_PWM_PIN);
        GyverPID mainDrivePid = GyverPID(MAIN_DRIVE_MOTOR_PID_KP, MAIN_DRIVE_MOTOR_PID_Ki, MAIN_DRIVE_MOTOR_PID_KD, MAIN_DRIVE_MOTOR_PID_DT);
        int speed = 124;
        int16_t joystickValue;
        float pitch;
        float pitchOffset;
        float yAngle;
        void calculateMaidDriveInput();
};