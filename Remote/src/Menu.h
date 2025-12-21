#pragma once

#include <Arduino.h>
#include "../Config.h"
#include "Display.h"
#include "JoystickControl.h"

class Menu {
    public:
        void init(JoystickControl* joystickControl);
        void navigate();
        void buttonOkClick();
        void buttonUpClick();
        void buttonDownClick();
        void buttonBackClick();
        void setSpeed(int speed);
        void setDirection(int direction);
        int getCalibrationId();
        void setBodyBattery(float bodyBattery);
        void setDomeBattery(float domeBattery);
    private:
        Display display = Display();
        int mode = 0;
        int pointer = 0;
        enum {
            INFO_SCREEN,
            MENU_SCREEN,
            DOME_REVERSE_SCREEN,
            DOME_CONFIG_SCREEN,
            BODY_CONFIG_SCREEN,
            JOYSTICK_CONFIG_SCREN,
            JOYSTICK_CALIBRATION_STEP_1_SCREEN,
            JOYSTICK_CALIBRATION_STEP_2_SCREEN,
            JOYSTICK_CALIBRATION_STEP_3_SCREEN,
            BODY_CONFIG_STEP_1_SCREEN,
            BODY_CONFIG_STEP_2_SCREEN,
            BODY_CONFIG_STEP_3_SCREEN,
        } modes;
        int maxMode = 11;
        int maxPointerByMode[12] {
            0, //INFO_SCREEN
            3, //MENU_SCREEN
            0, //DOME_REVERSE_SCREEN
            0, //DOME_CONFIG_SCREEN
            0, //BODY_CONFIG_SCREEN
            3, //JOYSTICK_CONFIG_SCREN
            0, //JOYSTICK_CALIBRATION_STEP_1_SCREEN
            0, //JOYSTICK_CALIBRATION_STEP_1_SCREEN
            0, //JOYSTICK_CALIBRATION_STEP_3_SCREEN
            0, //BODY_CONFIG_STEP_1_SCREEN
            0, //BODY_CONFIG_STEP_2_SCREEN
            0, //BODY_CONFIG_STEP_3_SCREEN
        };
        int nextModeMap[12][4] {
            {
                1 //INFO_SCREEN => MENU_SCREEN
            },
            {
                2, //MENU_SCREEN => DOME_REVERSE_SCREEN
                3, //MENU_SCREEN => DOME_CONFIG_SCREEN
                4, //MENU_SCREEN => BODY_CONFIG_SCREEN
                5  //MENU_SCREEN => JOYSTICK_CONFIG_SCREN
            },
            {
                0, // DOME_REVERSE_SCREEN => INFO_SCREEN
            },
            {
                0, // DOME_CONFIG_SCREEN => INFO_SCREEN
            },
            {
                9, // BODY_CONFIG_SCREEN => BODY_CONFIG_STEP_1_SCREEN
            },
            {
                6, // JOYSTICK_CONFIG_SCREN => JOYSTICK_CALIBRATION_STEP_1_SCREEN
                6, // JOYSTICK_CONFIG_SCREN => JOYSTICK_CALIBRATION_STEP_1_SCREEN
                6, // JOYSTICK_CONFIG_SCREN => JOYSTICK_CALIBRATION_STEP_1_SCREEN
                6, // JOYSTICK_CONFIG_SCREN => JOYSTICK_CALIBRATION_STEP_1_SCREEN
            },
            {
                7, // JOYSTICK_CALIBRATION_STEP_1_SCREEN => JOYSTICK_CALIBRATION_STEP_2_SCREEN
            },
            {
                8, // JOYSTICK_CALIBRATION_STEP_2_SCREEN => JOYSTICK_CALIBRATION_STEP_3_SCREEN
            },
            {
                0, // JOYSTICK_CALIBRATION_STEP_3_SCREEN => INFO_SCREEN
            },
            {
                10, // BODY_CONFIG_STEP_1_SCREEN => BODY_CONFIG_STEP_2_SCREEN
            },
            {
                11, // BODY_CONFIG_STEP_2_SCREEN => BODY_CONFIG_STEP_3_SCREEN
            },
            {
                0, // BODY_CONFIG_STEP_3_SCREEN => INFO_SCREEN
            }
        };
        int previousModeMap[9] {
            0, //INFO_SCREEN => INFO_SCREEN
            0, //MENU_SCREEN => INFO_SCREEN
            1, //DOME_REVERSE_SCREEN => MENU_SCREEN
            1, //DOME_CONFIG_SCREEN => MENU_SCREEN
            1, //BODY_CONFIG_SCREEN => MENU_SCREEN
            1, //JOYSTICK_CONFIG_SCREN => MENU_SCREEN
            5, //JOYSTICK_CALIBRATION_STEP_1_SCREEN => MENU_SCREEN
            5, //JOYSTICK_CALIBRATION_STEP_2_SCREEN => MENU_SCREEN
            5  //JOYSTICK_CALIBRATION_STEP_2_SCREEN => MENU_SCREEN
        };
        JoystickControl* joystickControl;
        int speed = 0;
        int direction = 0;
        int calibrationId = 0;
        float bodyBattery = 0;
        float domeBattery = 0;
        void modeAction();
};