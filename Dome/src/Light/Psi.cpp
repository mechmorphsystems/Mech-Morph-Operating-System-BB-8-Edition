#include "Psi.h"

void Psi::init()
{
    pixel.begin();
    
}

void Psi::low()
{
    pixel.setPixelColor(0, pixel.Color(60, 60, 60));
    pixel.show();
}

void Psi::fade()
{
    if (millis() - timer > 500)
    {
        pixel.setPixelColor(0, pixel.Color(60, 60, 60));
    }

    if (millis() - timer > 1000)
    {
        timer = millis();

        pixel.setPixelColor(0, pixel.Color(200, 200, 200));
    }

    pixel.show();
}

void Psi::randomBlink()
{
    if (millis() - timer > randomInterval)
    {
        timer = millis();
        randomInterval = random(100,300);

        pixel.setPixelColor(0, pixel.Color(random(0, 255),random(0, 255),random(0, 255)));
    }

    pixel.show();
}