#include <esp_now.h>
#include <WiFi.h>
#include <EasyTransfer.h>

// #define DEBUG

uint8_t domeAddress[] = {0x40, 0x22, 0xD8, 0x03, 0xBA, 0x68};

typedef struct BodyTransmitData {
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

typedef struct BodyReceiveData {
    int16_t psi = 0;
    int16_t domeLightMode = 0;
    float bodyBattery;
} BodyReceiveData;
 
BodyTransmitData bodyData;
BodyReceiveData bodyReceiveData;

EasyTransfer sendToBodyData;
EasyTransfer receiveFromBodyData;

uint32_t timer;
 
void OnDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&bodyData, incomingData, sizeof(bodyData));
    sendToBodyData.sendData();

    #ifdef DEBUG
    Serial.printf(
        "Receive from remote: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, \n",
        bodyData.TopLeftXJoystick,
        bodyData.TopLeftYJoystick,
        bodyData.TopRightXJoystick,
        bodyData.TopRightYJoystick,
        bodyData.BottomLeftXJoystick,
        bodyData.BottomRightXJoystick,
        bodyData.speed,
        bodyData.direction,
        bodyData.soundBip,
        bodyData.soundMusic,
        bodyData.calibrationId,
        bodyData.motorEnable,
        bodyData.domeLightMode
    );
    #endif
}

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    #ifdef DEBUG
    Serial.print("\r\nLast Packet Send Status:\t");
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
	#endif
}
 
void setup() {
    #ifdef DEBUG
    Serial.begin(115200);
    #endif

    Serial2.begin(57600);
    
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        return;
    }

    esp_now_register_send_cb(OnDataSent);
    
    esp_now_peer_info_t peerInfo = {};
    memcpy(peerInfo.peer_addr, domeAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        #ifdef DEBUG
        Serial.println("Failed to add peer");
        #endif

        return;
    }

    sendToBodyData.begin(details(bodyData), &Serial2);
    receiveFromBodyData.begin(details(bodyReceiveData), &Serial2);
    
    esp_now_register_recv_cb(OnDataReceive);
}

void loop() {
    if(receiveFromBodyData.receiveData()){
        #ifdef DEBUG
        Serial.printf(
            "Receive from body psi: %d, domeLightMode: %d, bodyBattery: %d\n",
            bodyReceiveData.psi,
            bodyReceiveData.domeLightMode,
            bodyReceiveData.bodyBattery
        );
        #endif

        esp_err_t result = esp_now_send(domeAddress, (uint8_t *) &bodyReceiveData, sizeof(bodyReceiveData));

        #ifdef DEBUG
        Serial.println(result == ESP_OK ? "Sent with success" : "Error sending the data");
        #endif
    }
}