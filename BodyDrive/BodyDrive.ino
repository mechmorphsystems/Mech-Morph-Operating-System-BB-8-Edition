#include <Arduino.h>
#include "src/Receivers/BodyReceiver.h"
#include "src/Receivers/ImuReceiver.h"
#include "src/Inputs.h"
#include "src/BodyMovement.h"
#include "src/DomeMovement.h"
#include "src/Calibration.h"
#include "src/Sounds.h"
#include "src/BodyTransmiter.h"
// #include "src/Light.h"
 
BodyReceiver bodyReceiver;
ImuReceiver imuReceiver;
Inputs inputs;

BodyMovement bodyMovement;
DomeMovement domeMovement;

Calibration calibration;

Sounds sounds;

BodyTransmiter bodyTransmiter;

uint32_t timer;

// EncButton2<EB_ENC> enc(INPUT, 20, 21);

void setup() {
    Serial.begin(115200);

    bodyReceiver.init();
    imuReceiver.init();

    calibration.init(&bodyReceiver, &imuReceiver, &inputs);
    
    domeMovement.init(&bodyReceiver, &imuReceiver, &calibration);
    bodyMovement.init(&bodyReceiver, &imuReceiver, &inputs, &calibration, &domeMovement);
    
    sounds.init(&bodyReceiver);

    bodyTransmiter.init(&bodyReceiver, &inputs);
}

void loop() {
    bodyReceiver.receiveData();
    imuReceiver.receiveData();

    calibration.checkCalibration();

    if (millis()- timer >= 20)
    {
        domeMovement.run();
        bodyMovement.run();
    }

    sounds.playSound();
    inputs.readBatteryVoltage();

    bodyTransmiter.sendData();



    // Serial.println(inputs.getBatteryVoltage());

    // enc.tick();
    // if (enc.turn()) {
    //     Serial.println("turn");

    //     // можно опросить ещё:
    //     Serial.println(enc.counter);  // вывести счётчик
    //     //Serial.println(enc.fast());   // проверить быстрый поворот
    //     Serial.println(enc.dir()); // направление поворота
    // }
}