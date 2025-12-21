#include <Arduino.h>

#define S2SpotPin A0

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.println(analogRead(S2SpotPin));
    delay(100);
}