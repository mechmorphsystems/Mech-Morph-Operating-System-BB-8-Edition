#include "DomeLogic.h"

void DomeLogic::init(uint8_t remoteAddress[6])
{
	#ifdef DEBUG
    Serial.begin(115200);
	#endif

    receiver.init();
    transmitter.init(remoteAddress);

    eye.init();
	largeLogic.init();
	smallLogic.init();
	holoprojector.init();
}

void DomeLogic::run()
{
    if (millis() - timer >= 40) {
        timer = millis();
        if (receiver.getBodyBattery() == 0) {
            needSend = true;
        }

        switch (receiver.getDomeLightMode())
		{
		case 0:
			eye.low();
			largeLogic.topWhite();
			smallLogic.low();
			holoprojector.disable();
			psi.low();
			break;
		case 1:
			eye.fade();
			largeLogic.fade();
			smallLogic.fade();
			holoprojector.pulse();
			psi.fade();
			break;
		case 2:
			eye.randomBlink();
			largeLogic.randomBlink();
			smallLogic.randomBlink();
			holoprojector.cycle();
			psi.randomBlink();
			break;
		default:
			break;
		}
  	}

	if (millis() - sendTimer >= 15000 || needSend) {
        sendTimer = millis();

		inputs.readBatteryVoltage();
        transmitter.setBodyBattery(receiver.getBodyBattery());
        transmitter.setDomeBattery(inputs.getBatteryVoltage());

        transmitter.send();
  	}
}