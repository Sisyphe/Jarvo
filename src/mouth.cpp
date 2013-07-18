#include "mouth.h"
#include <iostream>

//#define ESPEAK

#ifdef ESPEAK
#include <speak_lib.h>
#endif

Mouth::Mouth()
{
#ifdef ESPEAK
    espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 0, NULL,0);
    espeak_SetVoiceByName("eo");
#endif
}

void Mouth::speak(const std::string& n_str)
{
    //std::cout<< n_str << std::endl;

#ifdef ESPEAK
    espeak_Synth
    (
        n_str.c_str(),
        n_str.size(),
        0,
        POS_CHARACTER,
        0,
        espeakCHARS_AUTO,
        NULL,
        NULL
    );

    espeak_Synchronize();
#endif
}
