#include "Inputs.h"

void Inputs::readBatteryVoltage()
{
    if(millis() - lastBatteryUpdate >= 15000 || 0 == batteryVoltage){
      lastBatteryUpdate = millis();
      batteryVoltage = (analogRead(BATTERY_PIN) * 3.3 / 4096.0) / 0.5;
    }
}

float Inputs::getBatteryVoltage()
{
    return batteryVoltage;
}