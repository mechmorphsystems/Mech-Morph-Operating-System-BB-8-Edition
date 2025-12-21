#include "Eye.h"

void Eye::init()
{
    pixel.begin();
    pixel.setPixelColor(0, pixel.Color(0, 200, 0));
    pixel.show();
}

void Eye::low()
{
    for (int i = 1; i < 6; i++)
    {
        pixel.setPixelColor(i, pixel.Color(0, 0, 0));
        pixel.show();
    }
    
}

void Eye::fade()
{
    if (millis() - timer > 300)
    {
        timer = millis();
        switch (state)
        {
        case 0:
            pointer++;

            if (pointer > 5) {
                state = 1;
            } else {
                pixel.setPixelColor(pointer, pixel.Color(0, 200, 0));
            }
            
            break;
        case 1:
            pointer--;

            if (pointer <= 0) {
                state = 0;
            } else {
                pixel.setPixelColor(pointer, pixel.Color(0, 0, 0));
            }
            break;
        
        default:
            break;
        }

        pixel.show();
    }
}

void Eye::randomBlink()
{
    if (millis() - timer > 100)
    {
        timer = millis();

        if (pointer <= 0) {
            randomPointer = random(1, 5);
        }

        switch (state)
        {
        case 0:
            pointer++;

            if (pointer > randomPointer) {
                state = 1;
            } else {
                pixel.setPixelColor(pointer, pixel.Color(0, 200, 0));
            }
            
            break;
        case 1:
            pointer--;

            if (pointer <= 0) {
                state = 0;
            } else {
                pixel.setPixelColor(pointer, pixel.Color(0, 0, 0));
            }
            break;
        
        default:
            break;
        }

        pixel.show();
    }
    
}