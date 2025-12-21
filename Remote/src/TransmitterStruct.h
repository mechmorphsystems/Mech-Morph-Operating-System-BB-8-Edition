struct BodyTransmitData
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
};