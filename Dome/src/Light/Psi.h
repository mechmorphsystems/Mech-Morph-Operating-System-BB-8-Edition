#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Psi
{
    public:
        void init();
        void low();
        void fade();
        void randomBlink();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, PSI_PIN, NEO_GRB + NEO_KHZ800);
        uint32_t timer;
        uint16_t randomInterval = 0;
};
