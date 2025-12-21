#include "Menu.h"

void Menu::init(JoystickControl* joystickControl)
{
    Menu::joystickControl = joystickControl;
    display.init();
}

void Menu::navigate()
{
    display.setPointer(pointer);

    switch (mode)
    {
        case INFO_SCREEN: display.infoScreen(speed, direction, bodyBattery, domeBattery); break;
        case MENU_SCREEN: display.menuScreen(); break;
        case DOME_REVERSE_SCREEN: display.domeReverseScreen(); break;
        case DOME_CONFIG_SCREEN: display.domeConfigScreen(); break;
        case BODY_CONFIG_SCREEN: display.bodyConfigScreen(); break;
        case JOYSTICK_CONFIG_SCREN: display.joystickConfigScreen(); break;
        case JOYSTICK_CALIBRATION_STEP_1_SCREEN:
            display.joystickCalibrationStep1Screen(
                joystickControl->getSelectedJoystick()->getName(),
                joystickControl->getSelectedJoystick()->getXValue(),
                joystickControl->getSelectedJoystick()->getYValue()
            );
            break;
        case JOYSTICK_CALIBRATION_STEP_2_SCREEN:
            display.joystickCalibrationStep2Screen(
                joystickControl->getSelectedJoystick()->getName(),
                joystickControl->getSelectedJoystick()->calculateMinX(),
                joystickControl->getSelectedJoystick()->calculateMaxX(),
                joystickControl->getSelectedJoystick()->calculateMinY(),
                joystickControl->getSelectedJoystick()->calculateMaxY()
            );
            break;
        case JOYSTICK_CALIBRATION_STEP_3_SCREEN:
            display.joystickCalibrationStep3Screen();
            break;
        case BODY_CONFIG_STEP_1_SCREEN: display.bodyConfigStep1Screen(); break;
        case BODY_CONFIG_STEP_2_SCREEN: display.bodyConfigStep2Screen(); break;
        case BODY_CONFIG_STEP_3_SCREEN: display.bodyConfigStep3Screen(); break;
        default: break;
    }
}

void Menu::buttonOkClick()
{
    mode = nextModeMap[mode][pointer];
    
    if (mode > maxMode) {
        mode = 0;
    }

    modeAction();

    pointer = 0;   
}

void Menu::buttonUpClick()
{
    pointer--;
    if (pointer < 0) {
        pointer = maxPointerByMode[mode];
    }
}

void Menu::buttonDownClick()
{
    pointer++;
    if (pointer > maxPointerByMode[mode]) {
       pointer = 0;
    }
}

void Menu::buttonBackClick()
{
    mode = previousModeMap[mode];
}

void Menu::modeAction()
{
    switch (mode)
    {
        case JOYSTICK_CALIBRATION_STEP_1_SCREEN: joystickControl->setSelectedJoystick(pointer); break;
        case JOYSTICK_CALIBRATION_STEP_2_SCREEN: joystickControl->updateSelectedJoystickCenter(); break;
        case JOYSTICK_CALIBRATION_STEP_3_SCREEN:
            joystickControl->updateSelectedJoystickMinMax();
            joystickControl->saveJoystickConfig();
            break;
        case BODY_CONFIG_STEP_1_SCREEN: calibrationId = 3; break;
        case BODY_CONFIG_STEP_3_SCREEN: calibrationId = 4; break;
        default: break;
    }
}

void Menu::setSpeed(int speed)
{
    speed = speed;
}

void Menu::setDirection(int direction)
{
    direction = direction;
}

int Menu::getCalibrationId()
{
    return calibrationId;
}

void Menu::setBodyBattery(float bodyBattery)
{
    bodyBattery = bodyBattery;
}

void Menu::setDomeBattery(float domeBattery)
{
    domeBattery = domeBattery;
}