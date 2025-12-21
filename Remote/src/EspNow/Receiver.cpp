#include "Receiver.h"

typedef struct DomeData {
    float bodyBattery = 0;
    float domeBattery = 0;
} DomeData;
 
DomeData domeData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&domeData, incomingData, sizeof(domeData));

    #ifdef DEBUG
    Serial.printf(
        "Receive from dome bodyBattery: %d, domeBattery: %d\n",
        domeData.bodyBattery,
        domeData.domeBattery
    );
	#endif
}

void Receiver::init()
{
    esp_now_register_recv_cb(OnDataRecv);
}

float Receiver::getBodyBattery()
{
    return domeData.bodyBattery;
}

float Receiver::getDomeBattery()
{
    return domeData.domeBattery;
}