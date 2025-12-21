#include "Holoprojector.h"

void Holoprojector::init()
{
    pixel.begin();
}

void Holoprojector::disable()
{
    pixel.clear();
    pixel.setPixelColor(0, pixel.Color(0, 0, 0));
    pixel.show();
}

void Holoprojector::pulse()
{
    if(pulseState == 0 && blue <= 100) {
        blue++;
    }
    
    if(blue >= 100) {
        pulseState = 1;
    }
  
    if(pulseState == 1 && blue >= 10){
      blue--;
    }
    
    if(blue <= 10) {
        pulseState = 0;
    }
    
    pixel.setPixelColor(0, pixel.Color(0, 0, blue));
    pixel.show();
}

void Holoprojector::cycle()
{
    switch (cycleState)
    {
    case 0:
        red = 0;
        green = 0;
        blue = 0;
        cycleState = 1;
        break;
    case 1:
        if(red <= 250) {
            red += 3;
        } else {
            cycleState = 2;
        }
        break;
    case 2:
        if(red >= 10) {
            red -= 3;
        } else {
            cycleState = 3;
        }
        break;
    case 3:
        if(green <= 250) {
            green += 3;
        } else {
            cycleState = 4;
        }
        break;
    case 4:
        if(green >= 10) {
            green -= 3;
        } else {
            cycleState = 5;
        }
        break;
    case 5:
        if(blue <= 250) {
            blue += 3;
        } else {
            cycleState = 6;
        }
        break;
    case 6:
        if(blue >= 10) {
            blue -= 3;
        } else {
            cycleState = 7;
        }
        break;
    case 7:
        if(red <= 250) {
            red += 3;
        } else if(green <= 250) {
            green += 3;
        } else if(blue <= 250) {
            blue += 3;
        } else {
            cycleState = 8;
        }
        break;
    case 8:
        if(red >= 10) {
            red -= 3;
        } else if(green >= 10) {
            green -= 3;
        } else if(blue >= 10) {
            blue -= 3;
        } else {
            cycleState = 1;
        }
        break;
    
    default:
        break;
    }
  
    pixel.setPixelColor(0, pixel.Color(red, green, blue));
    pixel.show();
}