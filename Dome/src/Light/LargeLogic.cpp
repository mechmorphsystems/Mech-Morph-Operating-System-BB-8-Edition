#include "LargeLogic.h"

void LargeLogic::init()
{
    pixel.begin();
}

void LargeLogic::topWhite()
{
    pixel.clear();

    for (int i = 0; i < 2; i++) {
        pixel.setPixelColor(i, pixel.Color(47, 49, 50));
    }

    pixel.show();
}

void LargeLogic::fade()
{
    


    switch (fadeState)
    {
    case 0:
        fadeA++;
        if (fadeB > 0) {
            fadeB--;
        }
        break;
    case 1:
        fadeA--;
        fadeB++;
        break;
    default:
        break;
    }

    constrain(fadeA, 0, 50);
    constrain(fadeB, 0, 50);

    if(fadeA == 50){
        fadeState = 1;
    } else if (fadeA == 0){
        fadeState = 0;
    }

    pixel.setPixelColor(0, pixel.Color(fadeA, fadeA, fadeA)); 
    pixel.setPixelColor(1, pixel.Color(fadeA, fadeA, fadeA)); 
    pixel.setPixelColor(2, pixel.Color(fadeB, fadeB, fadeB)); 
    pixel.setPixelColor(3, pixel.Color(fadeB, fadeB, fadeB)); 
    pixel.show();

    
}

void LargeLogic::randomBlink()
{
    if(millis() - randomTimer > 300) {
      randomTimer = millis();

      pixel.setPixelColor(random(0, 6), pixel.Color(random(0, 255),random(0, 255),random(0, 255))); 
      pixel.show();
    }
}