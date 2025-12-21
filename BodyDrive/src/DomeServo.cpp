#include "DomeServo.h"

void DomeServo::init()
{
    DomeServo::leftServo.attach(LEFT_SERVO_PIN);
    DomeServo::rightServo.attach(RIGHT_SERVO_PIN);
    DomeServo::leftServo.write(95, 50, false);
    DomeServo::rightServo.write(90, 50, false);
}

void DomeServo::move()
{
    DomeServo::calculateXAngle();
    DomeServo::calculateYAngle();
    DomeServo::CalculateServoOffsets();

    DomeServo::leftServo.write(constrain(map(DomeServo::leftServoOffset, -90, 90, 0, 180),0, 180) + 5, DOME_SPEED, false);
    DomeServo::rightServo.write(constrain(map(DomeServo::rightServoOffset, -90, 90, 180, 0), 0, 180), DOME_SPEED, false);
}

void DomeServo::moveToCenter()
{
    DomeServo::leftServo.write(90, 50, false);
    DomeServo::rightServo.write(90, 50, false);
}

void DomeServo::setJoystickXValue(int16_t val, int8_t direction)
{
    if(direction == 0){
        DomeServo::joystickXValue = map(val, 0, 1024, -MAX_DOME_TILT_X, MAX_DOME_TILT_X);
    }else{
        DomeServo::joystickXValue = map(val, 0, 1024, MAX_DOME_TILT_X, -MAX_DOME_TILT_X);
    }

    if(DomeServo::joystickXValue <= 1.7 && DomeServo::joystickXValue >= -1.7){  
       DomeServo::joystickXValue = 0;   
    }
}

void DomeServo::setJoystickYValue(int16_t val, int8_t direction)
{
    if(direction == 0){
      DomeServo::joystickYValue = map(val, 0, 1024, -MAX_DOME_TILT_Y, MAX_DOME_TILT_Y);
    } else{
      DomeServo::joystickYValue = map(val, 0, 1024, MAX_DOME_TILT_Y, -MAX_DOME_TILT_Y);
    }

    if(DomeServo::joystickYValue <= 1.7 && DomeServo::joystickYValue >= -1.7){  
       DomeServo::joystickYValue = 0;   
    }
}

void DomeServo::setSpeed(int8_t speed)
{
    if (DomeServo::lastSpeedValue != speed)
    {
        DomeServo::lastSpeedValue = speed;

        DomeServo::speedMoveConstraint = DomeServo::speedMoveConstraintMap[speed];
    }
    
}

void DomeServo::setYPitchByMainDriveValue(int16_t val, float pitch, float pitchOffset)
{
    int maidDriveMap = constrain(map(val, 0, 1024, -100, 100), -100, 100);

    if(maidDriveMap >= DomeServo::speedMoveConstraint || maidDriveMap <= -DomeServo::speedMoveConstraint){
        DomeServo::yPitch = DomeServo::joystickYValue - (pitch + pitchOffset);
    } else{
        DomeServo::yPitch = DomeServo::joystickYValue - pitchOffset;
        // DomeServo::yPitch = DomeServo::joystickYValue;
    }
    // DomeServo::yPitch = DomeServo::joystickYValue;
}

float DomeServo::getYAngle()
{
    return DomeServo::yAngle;
}

void DomeServo::calculateXAngle()
{
    if((DomeServo::joystickXValue + DOME_X_SPEED) > DomeServo::xAngle && (DomeServo::joystickXValue - DOME_X_SPEED) < DomeServo::xAngle){
        DomeServo::xAngle = DomeServo::joystickXValue;
    } else if(DomeServo::xAngle > DomeServo::joystickXValue){
        DomeServo::xAngle -= DOME_X_SPEED;
    } else if(DomeServo::xAngle < DomeServo::joystickXValue){
        DomeServo::xAngle += DOME_X_SPEED;
    }
}
void DomeServo::calculateYAngle()
{
    if((DomeServo::yPitch + DOME_Y_SPEED) > DomeServo::yAngle && (DomeServo::yPitch - DOME_Y_SPEED) < DomeServo::yAngle){
        DomeServo::yAngle = DomeServo::yPitch;
    } else if(DomeServo::yAngle > DomeServo::yPitch){
        DomeServo::yAngle -= DOME_Y_SPEED;
    } else if(DomeServo::yAngle < DomeServo::yPitch){
        DomeServo::yAngle += DOME_Y_SPEED;
    }
}

void DomeServo::CalculateServoOffsets()
{
    if(DomeServo::yAngle < 0){
        DomeServo::yOffset = map(DomeServo::yAngle, -20, 0, 70, 0);
        DomeServo::xLowOffset = map(DomeServo::yOffset, 1, 70, -15, -50);
        DomeServo::xHighOffset= map(DomeServo::yOffset, 1, 70, 30, 20);
    } else if(DomeServo::yAngle> 0){
        DomeServo::yOffset = map(DomeServo::yAngle,0, 24, 0, -80); 
        DomeServo::xLowOffset = map(DomeServo::yOffset, -1, -80, -15, 10);
        DomeServo::xHighOffset = map(DomeServo::yOffset, -1, -80, 30, 90);
    } else{
      DomeServo::yOffset = 0;
    }
    
    if(DomeServo::xAngle> 0){
        DomeServo::leftServoOffset = DomeServo::yOffset + map(DomeServo::xAngle, 0, 18, 0,  DomeServo::xHighOffset);
        DomeServo::rightServoOffset = DomeServo::yOffset + map(DomeServo::xAngle, 0, 18, 0, DomeServo::xLowOffset);
     
    } else if(DomeServo::xAngle < 0){
        DomeServo::rightServoOffset = DomeServo::yOffset + map(DomeServo::xAngle, -18, 0,  DomeServo::xHighOffset, 0);
        DomeServo::leftServoOffset = DomeServo::yOffset + map(DomeServo::xAngle, -18, 0, DomeServo::xLowOffset, 0);
    } else{
        DomeServo::rightServoOffset = DomeServo::yOffset;
        DomeServo::leftServoOffset = DomeServo::yOffset;
    }
}
