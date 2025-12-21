#include "SmallLogic.h"

void SmallLogic::init()
{
    pixel.begin();
}

void SmallLogic::low()
{
    pixel.clear();

    for (int i = 0; i < 2; i++) {
        pixel.setPixelColor(i, pixel.Color(23, 67, 96));
    }

    pixel.show();
}

void SmallLogic::fade()
{
    switch (fadeState)
    {
    case 0:
        if(red < 24) {
            red++;
            green = map(red, 0, 23, 0, 67);
            blue = map(red, 0, 23, 0, 96);
        } else {
            fadeState = 1;
        }
        break;
    case 1:
        if(red > 0) {
            red--;
            green = map(red, 0, 23, 0, 67);
            blue = map(red, 0, 23, 0, 96);
        } else {
            fadeState = 0;
        }
        break;
    
    default:
        break;
    }

    for (int i = 0; i < 2; i++)
    {
        pixel.setPixelColor(i, pixel.Color(red, green, blue));
    }

    pixel.show();
}

void SmallLogic::randomBlink()
{
    if(millis() - randomTimer > 300) {
      randomTimer = millis();

      pixel.setPixelColor(random(0, 2), pixel.Color(random(0, 255),random(0, 255),random(0, 255))); 
      pixel.show();
    }
}