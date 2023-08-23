#include "raylib.h"

#ifndef MUSIC_H
#define MUSIC_H
void PlayMusic(Music bgm1, Music bgm2, bool& muted, bool& bgm_changer) {
    if (bgm_changer) {
        UpdateMusicStream(bgm2);
    }
    else {
        UpdateMusicStream(bgm1);
    }

    if (IsKeyPressed(KEY_M)) {
        if (muted) {
            SetMusicVolume(bgm1, 0.0f);
            SetMusicVolume(bgm2, 0.0f);
        }
        else {
            SetMusicVolume(bgm1, 0.3f);
            SetMusicVolume(bgm2, 0.3f);
        }

        muted = !muted; // Toggle the muted state
    }
}


#endif MUSIC_H