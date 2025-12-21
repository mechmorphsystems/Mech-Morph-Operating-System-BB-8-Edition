#pragma once

#include <Arduino.h>
#include "../Config.h"
#include "JoystickStruct.h"

class Joystick {
    public:
        Joystick(int xPin, int yPin);
        Joystick(int xPin, int yPin, char *name, bool reverseX, bool reverseY);
        int getXValue();
        int getYValue();
        char* getName();
        int calculateMinX();
        int calculateMaxX();
        int calculateMinY();
        int calculateMaxY();
        int getMinX();
        int getMaxX();
        int getMinY();
        int getMaxY();
        void setConfig(joystckConfig config);
        int getXValueForTransmit();
        int getYValueForTransmit();
    private:
        int xPin;
        int yPin;
        bool isSingleDirection = false;
        char *name = NULL;
        int minX = 4096;
        int maxX = 0;
        int minY = 4096;
        int maxY = 0;
        bool reverseX = false;
        bool reverseY = false;
        joystckConfig config;
};