#include "Inputs.h"

int16_t Inputs::getSideToSiePotValue()
{
    return map(analogRead(SIDE_TO_SIDE_POT_PIN), 0, 1024, 135,-135);
}

void Inputs::readBatteryVoltage()
{
    if(millis() - Inputs::lastBatteryUpdate >= 15000 || 0 == Inputs::batteryVoltage){
      Inputs::lastBatteryUpdate = millis();
      Inputs::batteryVoltage = (analogRead(BATTERY_VOLTAGE_PIN) * 5.2 / 1024.0) / 0.33;
    }
}

float Inputs::getBatteryVoltage()
{
    return Inputs::batteryVoltage;
}