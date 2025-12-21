#include "DomeMotor.h"

void DomeMotor::init()
{
    DomeMotor::motor.setMode(AUTO);
}

void DomeMotor::run(int val)
{
    DomeMotor::motor.setSpeed(constrain(map(val, 0, 1024, -255, 255), -255, 255));
}