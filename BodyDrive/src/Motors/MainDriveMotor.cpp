#include "MainDriveMotor.h"

void MainDriveMotor::init()
{
    MainDriveMotor::motor.setMode(AUTO);

    MainDriveMotor::mainDrivePid.setLimits(-255, 255);
}

void MainDriveMotor::run()
{
    // MainDriveMotor::motor.setSpeed(MainDriveMotor::mainDrivePid.getResult());
    MainDriveMotor::motor.setSpeed(MainDriveMotor::joystickValue);
}

void MainDriveMotor::setSpeed(int speed)
{
    MainDriveMotor::speed = speed;
}

void MainDriveMotor::setJoystickValue(int16_t val, int8_t direction)
{
    if(direction == 0)
    {
      MainDriveMotor::joystickValue = constrain(map(val, 0, 1024, -MainDriveMotor::speed, MainDriveMotor::speed), -MainDriveMotor::speed, MainDriveMotor::speed);
    }else{
      MainDriveMotor::joystickValue = constrain(map(val, 0, 1024, MainDriveMotor::speed, -MainDriveMotor::speed), MainDriveMotor::speed, -MainDriveMotor::speed);
    }

    MainDriveMotor::mainDrivePid.setpoint = constrain(MainDriveMotor::joystickValue, -55, 55);
}

void MainDriveMotor::setPitch(float pitch)
{
    MainDriveMotor::pitch = pitch;
}

void MainDriveMotor::setPitchOffset(float pitchOffset)
{
    MainDriveMotor::pitchOffset = pitchOffset;
}

void MainDriveMotor::setServoYAngle(float yAngle)
{
    MainDriveMotor::yAngle = yAngle;
}

void MainDriveMotor::calculateMaidDriveInput()
{
    MainDriveMotor::mainDrivePid.input = (MainDriveMotor::pitch + MainDriveMotor::pitchOffset) + (MainDriveMotor::yAngle /= 2);
}