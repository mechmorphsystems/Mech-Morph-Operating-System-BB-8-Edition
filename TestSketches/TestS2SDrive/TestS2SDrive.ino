#include <Arduino.h>

#define S2SenablePin 33 //If it doesn't work, try replacing it with 29
#define s2sPWM1 6
#define s2sPWM2 7

void setup() {
    pinMode(S2SenablePin, OUTPUT);
    pinMode(s2sPWM1, OUTPUT);
    pinMode(s2sPWM2, OUTPUT);
}

void loop() {
    digitalWrite(S2SenablePin, HIGH);

    analogWrite(s2sPWM1, 0);
    analogWrite(s2sPWM2, 255);   
    delay(10000);
    w
    analogWrite(s2sPWM1, 255);
    analogWrite(s2sPWM2, 0);
    delay(10000);
}