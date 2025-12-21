#pragma once

#include <Arduino.h>
#include "../Config.h"
#include "Receivers/BodyReceiver.h"
#include "Receivers/ImuReceiver.h"
#include "Inputs.h"
#include "Calibration.h"
#include "Motors/SideToSideMotor.h"
#include "Motors/FlywheelSpinMotor.h"
#include "Motors/MainDriveMotor.h"
#include "DomeMovement.h"

class BodyMovement
{
    public:
        void init(BodyReceiver* bodyReceiver, ImuReceiver* imuReveiver, Inputs* inputs, Calibration* calibration, DomeMovement* domeMovement);
        void run();
    private:
        BodyReceiver* bodyReceiver;
        ImuReceiver* imuReveiver;
        Inputs* inputs;
        Calibration* calibration;
        DomeMovement* domeMovement;
        SideToSideMotor sideToSideMotor = SideToSideMotor();
        FlywheelSpinMotor flywheelSpinMotor = FlywheelSpinMotor();
        MainDriveMotor mainDriveMotor = MainDriveMotor();
        int lastSpeedValue = 0;
        int speedMap[3] = {124, 186, 255};
        void enableMotor();
        void shutdownMotor();
        void setSpeed();
};