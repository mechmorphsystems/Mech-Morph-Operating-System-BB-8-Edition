#pragma once

#include <Arduino.h>
#include <DFRobotDFPlayerMini.h>
#include "../Config.h"
#include "Receivers/BodyReceiver.h"

class Sounds
{
    public:
        void init(BodyReceiver* bodyReceiver);
        void playSound();
    private:
        DFRobotDFPlayerMini myDFPlayer;
        BodyReceiver* bodyReceiver;
        int16_t lastSoundBip = 0;
        int16_t lastSoundMusic = 0;
        void playSoundBip();
        void playSoundMusic();
};