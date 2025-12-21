#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "../Config.h"

class Display {
    public:
        void init();
        void setPointer(int pointer);
        void infoScreen(int speed, int direction, float bodyBattery, float domeBattery);
        void menuScreen();
        void domeReverseScreen();
        void domeConfigScreen();
        void bodyConfigScreen();
        void joystickConfigScreen();
        void joystickCalibrationStep1Screen(char *joystickName, int valX, int valY);
        void joystickCalibrationStep2Screen(char *joystickName, int minX, int maxX, int minY, int maxY);
        void joystickCalibrationStep3Screen();
        void bodyConfigStep1Screen();
        void bodyConfigStep2Screen();
        void bodyConfigStep3Screen();
    private:
        Adafruit_SSD1306 display;
        String speedNameMap[3] = {"Slow              ", "Medium            ", "Fast              "};
        String directionNameMap[2] = {"Fwd", "Rev"};
        int pointer;
        void prepareForPrint();
        void printPointer();
        void printPointer(int alignment);
};