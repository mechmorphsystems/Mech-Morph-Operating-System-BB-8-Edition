#include "SideToSideMotor.h"

void SideToSideMotor::init()
{
    SideToSideMotor::motor.setMode(AUTO);

    SideToSideMotor::sideTosideTiltPid.setLimits(-255, 255);
    SideToSideMotor::sideTosideStabilityPid.setLimits(-255, 255);
}

void SideToSideMotor::run()
{
	SideToSideMotor::calcultaStabilitySetpoint();
	SideToSideMotor::calcultaStabilityInput();

	SideToSideMotor::calcultaTiltSetpoint();
	SideToSideMotor::calcultaTiltInput();
	
    SideToSideMotor::motor.setSpeed(constrain(map(SideToSideMotor::sideTosideTiltPid.getResult(), -255, 255, -255, 255), -255, 255));
}

void SideToSideMotor::setJoystickValue(int16_t val, int8_t direction)
{
    if(direction == 0){
        SideToSideMotor::joystickValue =  constrain(map(val, 0, 1024, -MAX_SIDE_TO_SIDE_TILT, MAX_SIDE_TO_SIDE_TILT), -MAX_SIDE_TO_SIDE_TILT, MAX_SIDE_TO_SIDE_TILT);
    }else{
        SideToSideMotor::joystickValue =  constrain(map(val, 0, 1024, -MAX_SIDE_TO_SIDE_TILT, MAX_SIDE_TO_SIDE_TILT), MAX_SIDE_TO_SIDE_TILT, -MAX_SIDE_TO_SIDE_TILT);
    }
}

void SideToSideMotor::setRoll(float roll)
{
    SideToSideMotor::roll = roll;
}

void SideToSideMotor::setRollOffset(float rollOffset)
{
	SideToSideMotor::rollOffset = rollOffset;
}

void SideToSideMotor::setSideTosidePot(int sideToSidePot)
{
	SideToSideMotor::sideToSidePot = sideToSidePot;
}

void SideToSideMotor::setSideTosidePotOffset(int sideToSidePotOffset)
{
	SideToSideMotor::sideToSidePotOffset = sideToSidePotOffset;
}

void SideToSideMotor::calcultaTiltSetpoint()
{
	SideToSideMotor::tiltSetpoint = map(
		constrain(SideToSideMotor::sideTosideStabilityPid.getResult(), -MAX_SIDE_TO_SIDE_TILT, MAX_SIDE_TO_SIDE_TILT),
		-MAX_SIDE_TO_SIDE_TILT,
		MAX_SIDE_TO_SIDE_TILT,
		MAX_SIDE_TO_SIDE_TILT,
		-MAX_SIDE_TO_SIDE_TILT
	);

	SideToSideMotor::sideTosideTiltPid.setpoint = SideToSideMotor::tiltSetpoint;
}

void SideToSideMotor::calcultaTiltInput()
{
	SideToSideMotor::tiltInput  = SideToSideMotor::sideToSidePot + SideToSideMotor::sideToSidePotOffset;

	SideToSideMotor::sideTosideTiltPid.input = SideToSideMotor::tiltInput;
}

void SideToSideMotor::calcultaStabilitySetpoint()
{
    if ((SideToSideMotor::stabilitySetpoint > -SIDE_TO_SIDE_SPEED) && (SideToSideMotor::stabilitySetpoint < SIDE_TO_SIDE_SPEED) && (SideToSideMotor::joystickValue == 0)){
      SideToSideMotor::stabilitySetpoint = 0;
    }else if ((SideToSideMotor::joystickValue > SideToSideMotor::stabilitySetpoint) && (SideToSideMotor::joystickValue != SideToSideMotor::stabilitySetpoint)){
      SideToSideMotor::stabilitySetpoint +=SIDE_TO_SIDE_SPEED;  
    }else if ((SideToSideMotor::joystickValue < SideToSideMotor::stabilitySetpoint) && (SideToSideMotor::joystickValue != SideToSideMotor::stabilitySetpoint)){
      SideToSideMotor::stabilitySetpoint -=SIDE_TO_SIDE_SPEED;
    }

    SideToSideMotor::stabilitySetpoint = constrain(SideToSideMotor::stabilitySetpoint, -MAX_SIDE_TO_SIDE_TILT, MAX_SIDE_TO_SIDE_TILT);

	SideToSideMotor::sideTosideStabilityPid.setpoint = SideToSideMotor::stabilitySetpoint;
}

void SideToSideMotor::calcultaStabilityInput()
{
	
	SideToSideMotor::stabilityInput = SideToSideMotor::roll + SideToSideMotor::rollOffset; 

	SideToSideMotor::sideTosideStabilityPid.input = SideToSideMotor::stabilityInput;
}