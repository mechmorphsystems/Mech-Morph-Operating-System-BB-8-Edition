#include "Sounds.h"

void Sounds::init(BodyReceiver* bodyReceiver)
{
    Sounds::bodyReceiver = bodyReceiver;

    Serial3.begin(9600);

    if (!Sounds::myDFPlayer.begin(Serial3)) {  //Use softwareSerial to communicate with mp3.
        // Serial.println(F("Unable to begin:"));
        // Serial.println(F("1.Please recheck the connection!"));
        // Serial.println(F("2.Please insert the SD card!"));
        while(true){
        delay(0); // Code to compatible with ESP8266 watch dog.
        }
    }
    // Serial.println(F("DFPlayer Mini online."));

    myDFPlayer.setTimeOut(500);
    myDFPlayer.volume(30);  //Set volume value. From 0 to 30
    
}

void Sounds::playSound()
{
    Sounds::playSoundBip();
    Sounds::playSoundMusic();
}

void Sounds::playSoundBip()
{
    if (Sounds::lastSoundBip != Sounds::bodyReceiver->getSoundBipValue())
    {
        Sounds::lastSoundBip = Sounds::bodyReceiver->getSoundBipValue();

        myDFPlayer.playFolder(1, random(1, 49));
    }
}

void Sounds::playSoundMusic()
{
    if (Sounds::lastSoundMusic != Sounds::bodyReceiver->getSoundMusicValue())
    {
        Sounds::lastSoundMusic = Sounds::bodyReceiver->getSoundMusicValue();

        if (6 == Sounds::bodyReceiver->getSoundMusicValue()) {
            myDFPlayer.playFolder(2, 42);
        }

        myDFPlayer.playFolder(2, Sounds::bodyReceiver->getSoundMusicValue());
    }
}