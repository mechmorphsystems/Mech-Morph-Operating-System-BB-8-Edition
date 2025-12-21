#pragma once

#include "../Config.h"
#include <esp_now.h>
#include <WiFi.h>
#include "JoystickControl.h"
#include "Controls.h"
#include "Menu.h"

class TransmitterAndReceiver {
    public:
        void init(uint8_t bodyAddress[]);
        void setJoystickControl(JoystickControl* joystickControl);
        void setButtonControl(Controls* buttonControl);
        void setMenu(Menu* menu);
        void sendData();
    private:
        JoystickControl* joystickControl;
        Controls* buttonControl;
        Menu* menu;
        uint8_t bodyAddress[6];
};