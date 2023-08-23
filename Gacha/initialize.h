#pragma once
#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "raylib.h"

using namespace std;

void PlayMusic(Music music, bool& muted, Music bgm) {
    UpdateMusicStream(bgm);

    if (IsKeyPressed(KEY_M)) {
        if (!muted)
        {
            StopMusicStream(music);
        }
        else
        {
            PlayMusicStream(music);
        }
    }

    muted = !muted;
}

void ToggleHelp(Texture background, int screenWidth, int screenHeight, bool& muted, Music bgm)
{

    while (true) {
        PlayMusic(bgm, muted, bgm);


        BeginDrawing();
        ClearBackground(ORANGE);
        DrawText("KEYBOARD SHORTCUTS:",
            screenWidth / 2 - MeasureText("KEYBOARD SHORTCUTS:", 60) / 2,
            screenHeight / 2 - 350, 60, WHITE);
        DrawText("M - mute music",
            screenWidth / 2 - MeasureText("M - mute music", 40) / 2,
            screenHeight / 2 - 286, 40, WHITE);
        DrawText("-Press I to Proceed-",
            screenWidth / 2 - MeasureText("-Press I to Proceed-", 64) / 2,
            screenHeight / 2 + 200, 64, WHITE);

        EndDrawing();

        if (IsKeyPressed(KEY_I)) {
            break;
        }
    }
}

#endif