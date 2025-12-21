#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Eye
{
    public:
        void init();
        void low();
        void fade();
        void randomBlink();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(6, EYE_PIN, NEO_GRB + NEO_KHZ800);
        uint8_t state = 0;
        int8_t pointer = 0;
        uint8_t randomPointer = 0;
        uint32_t timer;
};
