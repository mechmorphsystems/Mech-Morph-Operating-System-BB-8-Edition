#include "JoystickControl.h"

void JoystickControl::init()
{
    readConfigFromEeprom();
    // Serial.print("minX "); Serial.println(joystcksConfigs[2].minX);
    // Serial.print("centerX "); Serial.println(joystcksConfigs[2].centerX);
    // Serial.print("maxX "); Serial.println(joystcksConfigs[2].maxX);
    
    // Serial.print("minY "); Serial.println(joystcksConfigs[2].minY);
    // Serial.print("centerY "); Serial.println(joystcksConfigs[2].centerY);
    // Serial.print("maxY "); Serial.println(joystcksConfigs[2].maxY);
}

void JoystickControl::setSelectedJoystick(int selectedJoystick)
{
    selectedJoystick = selectedJoystick;
}

Joystick* JoystickControl::getSelectedJoystick()
{
    return &joysticks[selectedJoystick];
}

void JoystickControl::updateSelectedJoystickCenter()
{
    joystcksConfigs[selectedJoystick].centerX = getSelectedJoystick()->getXValue();
    joystcksConfigs[selectedJoystick].centerY = getSelectedJoystick()->getYValue();
}

void JoystickControl::updateSelectedJoystickMinMax()
{
    joystcksConfigs[selectedJoystick].minX = getSelectedJoystick()->getMinX();
    joystcksConfigs[selectedJoystick].maxX = getSelectedJoystick()->getMaxX();

    joystcksConfigs[selectedJoystick].minY = getSelectedJoystick()->getMinY();
    joystcksConfigs[selectedJoystick].maxY = getSelectedJoystick()->getMaxY();
}

void JoystickControl::saveJoystickConfig()
{
    // Serial.print("minX "); Serial.println(joystcksConfigs[selectedJoystick].minX);
    // Serial.print("centerX "); Serial.println(joystcksConfigs[selectedJoystick].centerX);
    // Serial.print("maxX "); Serial.println(joystcksConfigs[selectedJoystick].maxX);
    
    // Serial.print("minY "); Serial.println(joystcksConfigs[selectedJoystick].minY);
    // Serial.print("centerY "); Serial.println(joystcksConfigs[selectedJoystick].centerY);
    // Serial.print("maxY "); Serial.println(joystcksConfigs[selectedJoystick].maxY);
    joysticks[selectedJoystick].setConfig(joystcksConfigs[selectedJoystick]);
    EEPROM.put(CONFIG_ADDRESS, joystcksConfigs);
    EEPROM.commit();
}

void JoystickControl::readConfigFromEeprom()
{
    EEPROM.begin(256);
    if (EEPROM.read(INIT_ADDRESS) != 'w') {
        for (int i = 0; i < 3; i++)
        {
            joystckConfig initJoystckConfig;
            joystcksConfigs[i] = initJoystckConfig;
        }

        EEPROM.put(CONFIG_ADDRESS, joystcksConfigs);
        EEPROM.write(INIT_ADDRESS, 'w');
        EEPROM.commit();
    } else {
        EEPROM.get(CONFIG_ADDRESS, joystcksConfigs);
    }

    for (int i = 0; i < 3; i++)
    {
        joysticks[i].setConfig(joystcksConfigs[i]);
    }
}

BodyTransmitData JoystickControl::getJoystickControlTransmitData()
{
    BodyTransmitData data;
    data.TopLeftXJoystick = joysticks[LEFT_TOP].getXValueForTransmit();
    data.TopLeftYJoystick = joysticks[LEFT_TOP].getYValueForTransmit();
    data.TopRightXJoystick = joysticks[RIGHT_TOP].getXValueForTransmit();
    data.TopRightYJoystick = joysticks[RIGHT_TOP].getYValueForTransmit();

    data.BottomLeftXJoystick = joysticks[LEFT_BOTTOM].getXValueForTransmit();
    data.BottomRightXJoystick = joysticks[RIGHT_BOTTOM].getXValueForTransmit();

    return data;
}