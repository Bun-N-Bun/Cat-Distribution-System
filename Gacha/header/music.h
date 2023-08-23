#include "raylib.h"

#ifndef MUSIC_H
#define MUSIC_H
void PlayMusic(Music bgm1, Music bgm2, bool& muted, bool& bgm_changer) {
    if (bgm_changer) {
        UpdateMusicStream(bgm1);
    }
    else {
        UpdateMusicStream(bgm2);
    }

    if (IsKeyPressed(KEY_M)) {
        if (!muted) {
            StopMusicStream(bgm1);
            StopMusicStream(bgm2);
        }
        else {
            PlayMusicStream(bgm1);
            PlayMusicStream(bgm2);
        }
    }

    muted = !muted;
}

void PageFlip() {

}
#endif MUSIC_H