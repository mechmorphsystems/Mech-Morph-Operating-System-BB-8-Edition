#pragma once

#include <Arduino.h>
#include <EEPROM.h>
#include "../Config.h"
#include "Receivers/BodyReceiver.h"
#include "Receivers/ImuReceiver.h"
#include "Inputs.h"
#include "CalibrationStruct.h"

#define INIT_ADDRESS 0
#define CONFIG_ADDRESS 1

class Calibration
{
    public:
        void init(BodyReceiver* bodyReceiver, ImuReceiver* imuReveiver, Inputs* inputs);
        void checkCalibration();
        float getPitchOffset();
        float getRollOffset();
        int getSideToSidePotOffset();
    private:
        BodyReceiver* bodyReceiver;
        ImuReceiver* imuReveiver;
        Inputs* inputs;
        int lastCalibrationId = 0;
        enum {
            CALIBRATION_DEFAULT,
            DOME_SPIN_OFFSET_CALIBRATION,
            NO_CALIBRATION,
            PITCH_AND_DOME_TILT_OFFSET_CALIBRATION,
            SIDE_TO_SIDE_OFFSET_CALIBRATION
        } modes;
        calibrationConfig config;
        void readConfigFromEeprom();
        void setPitchOffset();
        void setRollOffset();
        void setSideToSidePotOffset();
        void saveConfigToEeprom();
};