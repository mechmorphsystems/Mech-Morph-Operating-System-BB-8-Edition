#pragma once

#include "Config.h"
#include "Constants.h"
#include <Arduino.h>
#include "src/JoystickControl.h"
#include "src/Menu.h"
#include "src/Controls.h"
#include "src/TransmitterAndReceiver.h"

JoystickControl joystickControl;
Menu menu;
Controls controls;
TransmitterAndReceiver transmitterAndReceiver;
int maxX=0;

uint32_t timer;

void setup()
{
    Serial.begin(115200);

    transmitterAndReceiver.init(bodyAddress);
    joystickControl.init();
    transmitterAndReceiver.setJoystickControl(&joystickControl);
    menu.init(&joystickControl);
    controls.init(&menu);
    transmitterAndReceiver.setMenu(&menu);
    transmitterAndReceiver.setButtonControl(&controls);

    
    Serial.println("Ready");
}

void loop()
{
    if (millis() - timer >= 20) {
        timer = millis();
        controls.readInput();
        menu.navigate();
        transmitterAndReceiver.sendData();

        // Serial.print("TopLeftXJoystick: "); Serial.println(joystickControl.getJoystickControlTransmitData().TopLeftXJoystick);
        // Serial.print("TopLeftYJoystick: "); Serial.println(joystickControl.getJoystickControlTransmitData().TopLeftYJoystick);
        // Serial.print("TopRightXJoystick: "); Serial.println(joystickControl.getJoystickControlTransmitData().TopRightXJoystick);
        // Serial.print("TopRightYJoystick: "); Serial.println(joystickControl.getJoystickControlTransmitData().TopRightYJoystick);

        // Serial.print("BottomLeftXJoystick: "); Serial.println(joystickControl.getJoystickControlTransmitData().BottomLeftXJoystick);
        // Serial.print("BottomRightXJoystick: "); Serial.println(joystickControl.getJoystickControlTransmitData().BottomRightXJoystick);

        // Serial.println("");
    }
}