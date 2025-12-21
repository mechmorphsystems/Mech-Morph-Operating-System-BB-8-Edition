#include "BodyMovement.h"

void BodyMovement::init(BodyReceiver* bodyReceiver, ImuReceiver* imuReveiver, Inputs* inputs, Calibration* calibration, DomeMovement* domeMovement)
{
    BodyMovement::bodyReceiver = bodyReceiver;
    BodyMovement::imuReveiver = imuReveiver;
    BodyMovement::inputs = inputs;
    BodyMovement::calibration = calibration;
    BodyMovement::domeMovement = domeMovement;

    pinMode(FLYWHEEL_SPIN_AND_MAIN_DRIVE_ENABLE_PIN, OUTPUT);
    pinMode(SIDE_TO_SIDE_ENABLE_PIN, OUTPUT);

    BodyMovement::sideToSideMotor.init();
    BodyMovement::flywheelSpinMotor.init();
    BodyMovement::mainDriveMotor.init();
}

void BodyMovement::run()
{
    BodyMovement::setSpeed();
    
    if (BodyMovement::bodyReceiver->isActive() && BodyMovement::imuReveiver->isActive() && BodyMovement::bodyReceiver->isEnabledMotor())
    {
        BodyMovement::enableMotor();

        BodyMovement::sideToSideMotor.setJoystickValue(BodyMovement::bodyReceiver->getTopRightXJoystickValue(), BodyMovement::bodyReceiver->getDirectionValue());
        BodyMovement::sideToSideMotor.setRoll(BodyMovement::imuReveiver->getRollValue());
        BodyMovement::sideToSideMotor.setRollOffset(BodyMovement::calibration->getRollOffset());
        BodyMovement::sideToSideMotor.setSideTosidePot(BodyMovement::inputs->getSideToSiePotValue());
        BodyMovement::sideToSideMotor.setSideTosidePotOffset(BodyMovement::calibration->getSideToSidePotOffset());
        BodyMovement::sideToSideMotor.run();


        BodyMovement::mainDriveMotor.setJoystickValue(BodyMovement::bodyReceiver->getTopRightYJoystickValue(), BodyMovement::bodyReceiver->getDirectionValue());
        BodyMovement::mainDriveMotor.setPitch(BodyMovement::imuReveiver->getPitchValue());
        BodyMovement::mainDriveMotor.setPitchOffset(BodyMovement::calibration->getPitchOffset());
        BodyMovement::mainDriveMotor.setServoYAngle(BodyMovement::domeMovement->getServoYAngle());
        BodyMovement::mainDriveMotor.run();

        BodyMovement::flywheelSpinMotor.run(BodyMovement::bodyReceiver->getBottomRightXJoystickValue());
    } else {
        BodyMovement::shutdownMotor();
    }
    
}

void BodyMovement::enableMotor()
{
    digitalWrite(FLYWHEEL_SPIN_AND_MAIN_DRIVE_ENABLE_PIN, HIGH);
    digitalWrite(SIDE_TO_SIDE_ENABLE_PIN, HIGH);
}

void BodyMovement::shutdownMotor()
{
    digitalWrite(FLYWHEEL_SPIN_AND_MAIN_DRIVE_ENABLE_PIN, LOW);
    digitalWrite(SIDE_TO_SIDE_ENABLE_PIN, LOW);
}

void BodyMovement::setSpeed()
{
    if (BodyMovement::lastSpeedValue != BodyMovement::bodyReceiver->getSpeedValue())
    {
        BodyMovement::lastSpeedValue = BodyMovement::bodyReceiver->getSpeedValue();

        BodyMovement::mainDriveMotor.setSpeed(BodyMovement::speedMap[BodyMovement::bodyReceiver->getSpeedValue()]);
    }
    
}