#include "Transmitter.h"

typedef struct BodyTransmitData
{
    int16_t TopLeftXJoystick = 512;
    int16_t TopLeftYJoystick = 512;

    int16_t TopRightXJoystick = 512;
    int16_t TopRightYJoystick = 512;

    int16_t BottomLeftXJoystick = 512;
    int16_t BottomRightXJoystick = 512;

    int16_t speed = 0;
    int16_t direction = 0;
    int16_t soundBip = 0;
    int16_t soundMusic = 0;
    int16_t calibrationId = 0;
    int16_t motorEnable = 0;
    int16_t domeLightMode = 0;
} BodyTransmitData;

BodyTransmitData bodyData;

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
    esp_err_t result = esp_now_send(remoteAddress, (uint8_t *) &bodyData, sizeof(bodyData));

    #ifdef DEBUG
    Serial.println(result == ESP_OK ? "Sent with success" : "Error sending the data");
    #endif
}

void Transmitter::setTopLeftXJoystick(int16_t value)
{
    bodyData.TopLeftXJoystick = value;
}

void Transmitter::setTopLeftYJoystick(int16_t value)
{
    bodyData.TopLeftYJoystick = value;
}

void Transmitter::setTopRightXJoystick(int16_t value)
{
    bodyData.TopRightXJoystick = value;
}

void Transmitter::setTopRightYJoystick(int16_t value)
{
    bodyData.TopRightYJoystick = value;
}

void Transmitter::setBottomLeftXJoystick(int16_t value)
{
    bodyData.BottomLeftXJoystick = value;
}

void Transmitter::setBottomRightXJoystick(int16_t value)
{
    bodyData.BottomRightXJoystick = value;
}

void Transmitter::setSpeed(int16_t value)
{
    bodyData.speed = value;
}

void Transmitter::setDirection(int16_t value)
{
    bodyData.direction = value;
}

void Transmitter::setSoundBip(int16_t value)
{
    bodyData.soundBip = value;
}

void Transmitter::setSoundMusic(int16_t value)
{
    bodyData.soundMusic = value;
}

void Transmitter::setCalibrationId(int16_t value)
{
    bodyData.calibrationId = value;
}

void Transmitter::setMotorEnable(int16_t value)
{
    bodyData.motorEnable = value;
}

void Transmitter::setDomeLightMode(int16_t value)
{
    bodyData.domeLightMode = value;
}
