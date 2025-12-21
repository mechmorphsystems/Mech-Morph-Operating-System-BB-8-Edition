#include "BodyReceiver.h"

BodyReceiveData bodyData;

void BodyReceiver::init()
{
    Serial1.begin(57600);

    BodyReceiver::ReceiveBody.begin(details(bodyData), &Serial1);

    BodyReceiver::active = false;
}

void BodyReceiver::receiveData()
{
    if(BodyReceiver::ReceiveBody.receiveData()){
        BodyReceiver::active = true;
        BodyReceiver::lastReceiveDataTime = millis();
        // Serial.print(bodyData.TopLeftXJoystick); Serial.print(", ");
        // Serial.print(bodyData.TopLeftYJoystick); Serial.print(", ");
        // Serial.print(bodyData.TopRightXJoystick); Serial.print(", ");
        // Serial.print(bodyData.TopRightYJoystick); Serial.print(", ");
        // Serial.print(bodyData.BottomLeftXJoystick); Serial.print(", ");
        // Serial.print(bodyData.BottomRightXJoystick); Serial.print(", ");
        // Serial.print(bodyData.speed); Serial.print(", ");
        // Serial.print(bodyData.direction); Serial.print(", ");
        // Serial.print(bodyData.soundBip); Serial.print(", ");
        // Serial.print(bodyData.soundMusic); Serial.print(", ");
        // Serial.print(bodyData.calibrationId); Serial.print(", ");
        // Serial.print(bodyData.motorEnable); Serial.print(", ");
        // Serial.println(bodyData.domeLightMode);
    }

    BodyReceiver::checkLastReceiveData();
}

bool BodyReceiver::isActive()
{
    return BodyReceiver::active;
}

int16_t BodyReceiver::getTopLeftXJoystickValue()
{
    return bodyData.TopLeftXJoystick;
}

int16_t BodyReceiver::getTopLeftYJoystickValue()
{
    return bodyData.TopLeftYJoystick;
}

int16_t BodyReceiver::getTopRightXJoystickValue()
{
    return bodyData.TopRightXJoystick;
}

int16_t BodyReceiver::getTopRightYJoystickValue()
{
    return bodyData.TopRightYJoystick;
}

int16_t BodyReceiver::getBottomLeftXJoystickValue()
{
    return bodyData.BottomLeftXJoystick;
}

int16_t BodyReceiver::getBottomRightXJoystickValue()
{
    return bodyData.BottomRightXJoystick;
}

int16_t BodyReceiver::getSpeedValue()
{
    return bodyData.speed;
}

int16_t BodyReceiver::getDirectionValue()
{
    return bodyData.direction;
}

int16_t BodyReceiver::getSoundBipValue()
{
    return bodyData.soundBip;
}

int16_t BodyReceiver::getSoundMusicValue()
{
    return bodyData.soundMusic;
}

int16_t BodyReceiver::getCalibrationIdValue()
{
    return bodyData.calibrationId;
}

int16_t BodyReceiver::isEnabledMotor()
{
    return bodyData.motorEnable;
}

int16_t BodyReceiver::getDomeLightMode()
{
    return bodyData.domeLightMode;
}

void BodyReceiver::checkLastReceiveData()
{
    if (millis() - BodyReceiver::lastReceiveDataTime > 15000)
    {
        BodyReceiver::active = false;
    }
}