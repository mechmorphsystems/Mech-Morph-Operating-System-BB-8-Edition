#include "Transmitter.h"

typedef struct SendRemoteData {
    float bodyBattery = 0;
    float domeBattery = 0;
} SendRemoteData;
 
SendRemoteData remoteData;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    #ifdef DEBUG
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
	#endif
}

void Transmitter::init(uint8_t remoteAddress[6])
{
    esp_now_peer_info_t peerInfo = {};
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;

    esp_now_register_send_cb(OnDataSent);

    memcpy(peerInfo.peer_addr, remoteAddress, 6);
    memcpy(Transmitter::remoteAddress, remoteAddress, 6);
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        #ifdef DEBUG
        Serial.println("Failed to add peer");
        #endif

        return;
    }
}

void Transmitter::send()
{
    esp_err_t result = esp_now_send(remoteAddress, (uint8_t *) &remoteData, sizeof(remoteData));

    #ifdef DEBUG
    Serial.println(result == ESP_OK ? "Sent with success" : "Error sending the data");
    #endif
}

void Transmitter::setBodyBattery(float bodyBattery)
{
    remoteData.bodyBattery = bodyBattery;
}

void Transmitter::setDomeBattery(float domeBattery)
{
    remoteData.domeBattery = domeBattery;
}