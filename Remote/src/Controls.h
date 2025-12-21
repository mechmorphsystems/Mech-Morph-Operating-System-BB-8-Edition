#pragma once

#include "../Config.h"
#include <Arduino.h>
#include <OneButton.h>
#include "Menu.h"

class Controls {
    public:
        void init(Menu* menu);
        void readInput();
        void leftTopJoystickButtonClick();
        void rightTopJoystickButtonClick();
        void leftLeftButtonClick();
        void leftUpButtonClick();
        void leftDownButtonClick();
        void leftRightButtonClick();
        void rightLeftButtonClick();
        void rightUpButtonClick();
        void rightDownButtonClick();
        void rightRightButtonClick();
        void rightDownButtonDoubleClick();
        int getSpeed();
        int getDirection();
        int getSoundBip();
        int getSoundMusic();
        int getMotorEnable();
        int getDomeLightMode();
    private:
        OneButton buttons[10] {
            // joystick buttons
            OneButton(LEFT_TOP_JOYSTICK_BUTTON_PIN, true, true),
            OneButton(RIGHT_TOP_JOYSTICK_BUTTON_PIN, true, true),
            // left buttons
            OneButton(LEFT_LEFT_BUTTON_PIN, true, true),
            OneButton(LEFT_UP_BUTTON_PIN, true, true),
            OneButton(LEFT_DOWN_BUTTON_PIN, true, true),
            OneButton(LEFT_RIGHT_BUTTON_PIN, true, true),
            // // right buttons
            OneButton(RIGHT_LEFT_BUTTON_PIN, true, true),
            OneButton(RIGHT_UP_BUTTON_PIN, true, true),
            OneButton(RIGHT_DOWN_BUTTON_PIN, true, true),
            OneButton(RIGHT_RIGHT_BUTTON_PIN, true, true)
        };
        enum {
             // joystick buttons
            LEFT_TOP_JOYSTICK_BUTTON,
            RIGHT_TOP_JOYSTICK_BUTTON,
            // left buttons
            LEFT_LEFT_BUTTON,
            LEFT_UP_BUTTON,
            LEFT_DOWN_BUTTON,
            LEFT_RIGHT_BUTTON,
            // right buttons
            RIGHT_LEFT_BUTTON,
            RIGHT_UP_BUTTON,
            RIGHT_DOWN_BUTTON,
            RIGHT_RIGHT_BUTTON,
        } buttonNames;
        Menu* menu;
        int speed = 0;
        int direction = 0;
        int soundBip = 0;
        int soundMusic = 0;
        int domeLightMode = 0;
};
        