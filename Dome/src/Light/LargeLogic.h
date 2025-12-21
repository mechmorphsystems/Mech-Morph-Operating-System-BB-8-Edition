#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class LargeLogic
{
    public:
        void init();
        void topWhite();
        void fade();
        void randomBlink();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(4, LARGE_LOGIC_PIN, NEO_GRB + NEO_KHZ800);
        uint8_t fadeState = 0;
        uint8_t fadeA = 0;
        uint8_t fadeB = 0;
        uint32_t randomTimer;
};
