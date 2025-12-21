#include "BodyTransmiter.h"

BodyTransmitData bodyTransmitData;

void BodyTransmiter::init(BodyReceiver* bodyReceiver, Inputs* inputs)
{
    BodyTransmiter::bodyReceiver = bodyReceiver;
    BodyTransmiter::inputs = inputs;

    BodyTransmiter::transmitBody.begin(details(bodyTransmitData), &Serial1);
}

void BodyTransmiter::sendData()
{
    if (bodyTransmitData.domeLightMode != BodyTransmiter::bodyReceiver->getDomeLightMode())
    {
        BodyTransmiter::needSend = true;
        bodyTransmitData.domeLightMode = BodyTransmiter::bodyReceiver->getDomeLightMode();
    }

    if (bodyTransmitData.bodyBattery != BodyTransmiter::inputs->getBatteryVoltage())
    {
        BodyTransmiter::needSend = true;
        bodyTransmitData.bodyBattery = BodyTransmiter::inputs->getBatteryVoltage();
    }
    
    if (BodyTransmiter::needSend)
    {
        BodyTransmiter::needSend = false;
        BodyTransmiter::transmitBody.sendData();
    }
}