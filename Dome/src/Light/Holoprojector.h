#pragma once

#include "../../Config.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class Holoprojector
{
    public:
        void init();
        void disable();
        void pulse();
        void cycle();
    private:
        Adafruit_NeoPixel pixel = Adafruit_NeoPixel(1, HOLOPROJECTOR_PIN, NEO_GRB + NEO_KHZ800);
        uint8_t pulseState = 0;
        uint8_t cycleState = 0;
        uint8_t red = 0;
        uint8_t green = 0;
        uint8_t blue = 0;
};
