#pragma once

#include "../Config.h"
#include <Arduino.h>
#include <EEPROM.h>
#include "Joystick.h"
#include "TransmitterStruct.h"

#define INIT_ADDRESS 0
#define CONFIG_ADDRESS 1

class JoystickControl {
    public:
        void init();
        void setSelectedJoystick(int selectedJoystick);
        Joystick* getSelectedJoystick();
        void updateSelectedJoystickCenter();
        void updateSelectedJoystickMinMax();
        void saveJoystickConfig();
        BodyTransmitData getJoystickControlTransmitData();
    private:
        Joystick joysticks[4] {
            Joystick(LEFT_TOP_JOYSTICK_X_PIN, LEFT_TOP_JOYSTICK_Y_PIN, "Top left", true, true),
            Joystick(RIGHT_TOP_JOYSTICK_X_PIN, RIGHT_TOP_JOYSTICK_Y_PIN, "Top right", false, false),
            Joystick(LEFT_BOTTOM_JOYSTICK_X_PIN, 0, "Bottom left", true, false),
            Joystick(RIGHT_BOTTOM_JOYSTICK_X_PIN, 0, "Bottom right", false, false)
        };
        enum {
            LEFT_TOP,
            RIGHT_TOP,
            LEFT_BOTTOM,
            RIGHT_BOTTOM
        } joysticNames;
        joystckConfig joystcksConfigs[4];
        int selectedJoystick = -1;
        void readConfigFromEeprom();
};