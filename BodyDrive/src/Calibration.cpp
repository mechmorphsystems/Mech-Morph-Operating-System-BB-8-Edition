#include "Calibration.h"

void Calibration::init(BodyReceiver* bodyReceiver, ImuReceiver* imuReveiver, Inputs* inputs)
{
    Calibration::bodyReceiver = bodyReceiver;
    Calibration::imuReveiver = imuReveiver;
    Calibration::inputs = inputs;

    Calibration::readConfigFromEeprom();
}

float Calibration::getPitchOffset()
{
    return Calibration::config.pitchOffset;
}

float Calibration::getRollOffset()
{
    return Calibration::config.rollOffset;
}

int Calibration::getSideToSidePotOffset()
{
    return Calibration::config.sideToSitePotOffset;
}

void Calibration::checkCalibration()
{
    if (Calibration::lastCalibrationId != Calibration::bodyReceiver->getCalibrationIdValue())
    {
        Calibration::lastCalibrationId = Calibration::bodyReceiver->getCalibrationIdValue();

        switch (Calibration::bodyReceiver->getCalibrationIdValue())
        {
        case PITCH_AND_DOME_TILT_OFFSET_CALIBRATION:
            Calibration::setPitchOffset();
            break;
        case SIDE_TO_SIDE_OFFSET_CALIBRATION:
            Calibration::setRollOffset();
            Calibration::setSideToSidePotOffset();
            Calibration::saveConfigToEeprom();
            break;
        default:
            break;
        }
    }
}

void Calibration::readConfigFromEeprom()
{
    if (EEPROM.read(INIT_ADDRESS) != 'w') {
        Calibration::saveConfigToEeprom();
        EEPROM.write(INIT_ADDRESS, 'w');
    } else {
        EEPROM.get(CONFIG_ADDRESS, Calibration::config);
    }
}

void Calibration::setPitchOffset()
{
    if(Calibration::imuReveiver->getPitchValue() < 0){
        Calibration::config.pitchOffset = abs(Calibration::imuReveiver->getPitchValue());
    }else{
        Calibration::config.pitchOffset = Calibration::imuReveiver->getPitchValue() * -1;
    }
}

void Calibration::setRollOffset()
{
    if(Calibration::imuReveiver->getRollValue() < 0){
        Calibration::config.rollOffset = abs(Calibration::imuReveiver->getRollValue());
    }else{
        Calibration::config.rollOffset = Calibration::imuReveiver->getRollValue() * -1;
    }
}

void Calibration::setSideToSidePotOffset()
{
    if(Calibration::inputs->getSideToSiePotValue() < 0){
      Calibration::config.sideToSitePotOffset = abs(Calibration::inputs->getSideToSiePotValue());
    }else{
      Calibration::config.sideToSitePotOffset = Calibration::inputs->getSideToSiePotValue() * -1;
    }
}

void Calibration::saveConfigToEeprom()
{
    EEPROM.put(CONFIG_ADDRESS, Calibration::config);
}