#include "Joystick.h"

Joystick::Joystick(int xPin, int yPin)
{
    xPin = xPin;
    
    if (yPin == 0) {
        isSingleDirection = true;
    } else {
        yPin = yPin;
    }
    
}

Joystick::Joystick(int xPin, int yPin, char *name, bool reverseX, bool reverseY)
{
    xPin = xPin;

    if (yPin == 0) {
        isSingleDirection = true;
    } else {
        yPin = yPin;
    }

    name = name;
    reverseX = reverseX;
    reverseY = reverseY;
}

int Joystick::getXValue()
{
    if (reverseX) {
        return constrain(map(analogRead(xPin), 0, 4096, 4096, 0), 0, 4096);
    }
    
    return analogRead(xPin);
}

int Joystick::getYValue()
{
    if (isSingleDirection) {
        return 2096;
    }

    if (reverseY) {
        return constrain(map(analogRead(yPin), 0, 4096, 4096, 0), 0, 4096);
    }
    
    return analogRead(yPin);
}

char* Joystick::getName()
{
    return name;
}

int Joystick::calculateMinX()
{
    if (getXValue() < minX) {
        minX = getXValue();
    }

    return minX;
}

int Joystick::calculateMaxX()
{
    if (getXValue() > maxX) {
        maxX = getXValue();
    }

    return maxX;
}

int Joystick::calculateMinY()
{
    int yValue = getYValue();

    if (yValue < minY) {
        minY = yValue;
    }

    return minY;
}

int Joystick::calculateMaxY()
{
    int yValue = getYValue();

    if (yValue > maxY) {
        maxY = yValue;
    }

    return maxY;
}

int Joystick::getMinX()
{
    return minX;
}

int Joystick::getMaxX()
{
    return maxX;
}

int Joystick::getMinY()
{
    return minY;
}

int Joystick::getMaxY()
{
    return maxY;
}

void Joystick::setConfig(joystckConfig config)
{
    config = config;
}

int Joystick::getXValueForTransmit()
{
    if (getXValue() > (config.centerX - 300) && getXValue() < (config.centerX + 300))
    {
        return 512;
    }
    

    return constrain(map(getXValue(), config.minX, config.maxX, 0, 1023), 0, 1023);
}

int Joystick::getYValueForTransmit()
{
    if (getYValue() > (config.centerY - 300) && getYValue() < (config.centerY + 300))
    {
        return 512;
    }
    

    return constrain(map(getYValue(), config.minY, config.maxY, 0, 1023), 0, 1023);
}