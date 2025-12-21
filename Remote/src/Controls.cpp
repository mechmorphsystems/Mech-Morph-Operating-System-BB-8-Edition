#include "Controls.h"

void Controls::init(Menu* menu)
{
    Controls::menu = menu;

    buttons[LEFT_TOP_JOYSTICK_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftTopJoystickButtonClick();}, this);
    buttons[RIGHT_TOP_JOYSTICK_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightTopJoystickButtonClick();}, this);

    buttons[LEFT_LEFT_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftLeftButtonClick();}, this);
    buttons[LEFT_UP_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftUpButtonClick();}, this);
    buttons[LEFT_DOWN_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftDownButtonClick();}, this);
    buttons[LEFT_RIGHT_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->leftRightButtonClick();}, this);

    buttons[RIGHT_LEFT_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightLeftButtonClick();}, this);
    buttons[RIGHT_UP_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightUpButtonClick();}, this);
    buttons[RIGHT_DOWN_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightDownButtonClick();}, this);
    buttons[RIGHT_DOWN_BUTTON].attachDoubleClick([](void *scope) { ((Controls *) scope)->rightDownButtonDoubleClick();}, this);
    buttons[RIGHT_RIGHT_BUTTON].attachClick([](void *scope) { ((Controls *) scope)->rightRightButtonClick();}, this);

    pinMode(MOTOR_ENABLE_PIN, INPUT_PULLUP);
}

void Controls::readInput()
{
    for (int i = 0; i < 10; i++) {
        buttons[i].tick();
    }
}

void Controls::leftTopJoystickButtonClick()
{
    Serial.println("leftTopJoystickButtonClick");
    direction = !direction;
    menu->setDirection(direction);
}

void Controls::rightTopJoystickButtonClick()
{
    Serial.println("rightTopJoystickButtonClick");
}

void Controls::leftLeftButtonClick()
{
    Serial.println("buttonBackClick");
    menu->buttonBackClick();
}

void Controls::leftUpButtonClick()
{
    Serial.println("buttonUpClick");
    menu->buttonUpClick();
}

void Controls::leftDownButtonClick()
{
    Serial.println("buttonDownClick");
    menu->buttonDownClick();
}

void Controls::leftRightButtonClick()
{
    Serial.println("buttonOkClick");
    menu->buttonOkClick();
}

void Controls::rightLeftButtonClick()
{
    Serial.println("rightLeftButtonClick");
    speed++;
    if(speed > 2) {
        speed = 0;
    }

    menu->setSpeed(speed);
}

void Controls::rightUpButtonClick()
{
    Serial.println("rightUpButtonClick");
    domeLightMode++;
    if(domeLightMode > 2) {
        domeLightMode = 0;
    }
}

void Controls::rightDownButtonClick()
{
    Serial.println("rightDownButtonClick");
    soundMusic++;
    if(soundMusic > 5) {
        soundMusic = 0;
    }
}

void Controls::rightDownButtonDoubleClick()
{
    Serial.println("rightDownButtonDoubleClick");

    soundMusic = 6;
}


void Controls::rightRightButtonClick()
{
    Serial.println("rightRightButtonClick");
    soundBip = !soundBip;
}

int Controls::getSpeed()
{
    return speed;
}

int Controls::getDirection()
{
    return direction;
}

int Controls::getSoundBip()
{
    return soundBip;
}

int Controls::getSoundMusic()
{
    return soundMusic;
}

int Controls::getMotorEnable()
{
    return digitalRead(MOTOR_ENABLE_PIN);
}

int Controls::getDomeLightMode()
{
    return domeLightMode;
}