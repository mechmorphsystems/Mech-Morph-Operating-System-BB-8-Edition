#pragma once

#include <Arduino.h>
#include "../Config.h"
#include <VarSpeedServo.h>

class DomeServo
{
    public:
        void init();
        void move();
        void moveToCenter();
        void setJoystickXValue(int16_t val, int8_t direction);
        void setJoystickYValue(int16_t val, int8_t direction);
        void setSpeed(int8_t speed);
        void setYPitchByMainDriveValue(int16_t val, float pitch, float pitchOffset);
        float getYAngle();
    private:
        VarSpeedServo leftServo;
        VarSpeedServo rightServo;
        int16_t joystickXValue;
        int16_t joystickYValue;
        int8_t lastSpeedValue = 0;
        int speedMoveConstraintMap[3] = {20, 15, 10};
        int speedMoveConstraint = 20;
        float yPitch;
        float xAngle;
        float yAngle;
        int leftServoOffset = 90;
        int rightServoOffset = 90;
        int xLowOffset;
        int xHighOffset;
        int yOffset;
        void calculateXAngle();
        void calculateYAngle();
        void CalculateServoOffsets();
};