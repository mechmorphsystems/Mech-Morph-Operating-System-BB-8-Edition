#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class SmallLogic
{
    public:
        void init();
        void low();
        void fade();
        void randomBlink();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(2, SMALL_LOGIC_PIN, NEO_GRB + NEO_KHZ800);
        uint8_t fadeState = 0;
        uint8_t red = 0;
        uint8_t green = 0;
        uint8_t blue = 0;
        uint32_t randomTimer;
};
