#include "raylib.h"

#ifndef SCREEN_H
#define SCREEN_H
enum Screen{
    SCREEN_MENU,
    SCREEN_HELP,
    SCREEN_GAME,
    SCREEN_PULL,
    SCREEN_CATCOLLECTION1,
    SCREEN_CATCOLLECTION2,
    SCREEN_CATCOLLECTION3,
    SCREEN_CATCOLLECTION4
};

void Animation(Texture BG_GAME, Texture box2, Texture& sprite, int SCREEN_WIDTH, int SCREEN_HEIGHT, Rectangle frames[], int currentFrame) {
    DrawTexture(BG_GAME, 0, 0, WHITE);
    DrawTexture(box2, (SCREEN_WIDTH / 2 - (box2.width / 2)), SCREEN_HEIGHT / 2 - 120, WHITE);
    DrawTextureRec(sprite, frames[currentFrame],
        { SCREEN_WIDTH / 2 - frames[currentFrame].width / 2,
        SCREEN_HEIGHT / 2 - frames[currentFrame].height / 2 }, WHITE);
}

void AnimationTImer(float timer2, float frameTime, int currentFrame) {
    timer2 += GetFrameTime();

    if (timer2 >= frameTime) {
        currentFrame = (currentFrame + 1) % 6;
        timer2 = 0.0f;
    }
}

void WindowDisplay(Screen& currentScreen, Screen& previousScreen, 
    Sound starting, Sound pageflip, bool& indexToggle, int& pull, bool& checker) {
    if (currentScreen == SCREEN_MENU) {
        if (IsKeyPressed(KEY_ENTER)) {
            PlaySound(starting);
            currentScreen = SCREEN_HELP;
        }
    }
    else if (currentScreen == SCREEN_HELP) {
        if (IsKeyPressed(KEY_ENTER)) {
            currentScreen = SCREEN_GAME;
        }
    }
    else if (currentScreen == SCREEN_GAME) {
        if (IsKeyPressed(KEY_ENTER)) {
            currentScreen = SCREEN_HELP;
        }
        else if (IsKeyPressed(KEY_C)) {
            currentScreen = SCREEN_CATCOLLECTION1;
        }
        else if (IsKeyPressed(KEY_SPACE)){
            indexToggle = true;
            checker = true;
            currentScreen = SCREEN_PULL;
        }
    }
    else if (currentScreen == SCREEN_PULL) {
        if (IsKeyPressed(KEY_SPACE)) {
            currentScreen = SCREEN_GAME;
        }
    }
    else if (currentScreen == SCREEN_CATCOLLECTION1) {
        if (IsKeyPressed(KEY_RIGHT)) {
            PlaySound(pageflip);
            previousScreen = currentScreen;
            currentScreen = SCREEN_CATCOLLECTION2;
        }
        else if (IsKeyPressed(KEY_C)) {
            PlaySound(pageflip);
            currentScreen = SCREEN_GAME;
        }
    }
    else if (currentScreen == SCREEN_CATCOLLECTION2) {
        if (IsKeyPressed(KEY_RIGHT)) {
            PlaySound(pageflip);
            previousScreen = currentScreen;
            currentScreen = SCREEN_CATCOLLECTION3;
        }
        else if (IsKeyPressed(KEY_LEFT)) {
            PlaySound(pageflip);
            previousScreen = currentScreen;
            currentScreen = SCREEN_CATCOLLECTION1;
        }
        else if (IsKeyPressed(KEY_C)) {
            PlaySound(pageflip);
            currentScreen = SCREEN_GAME;
        }
    }
    else if (currentScreen == SCREEN_CATCOLLECTION3) {
        if (IsKeyPressed(KEY_RIGHT)) {
            PlaySound(pageflip);
            previousScreen = currentScreen;
            currentScreen = SCREEN_CATCOLLECTION4;
        }
        else if (IsKeyPressed(KEY_LEFT)) {
            PlaySound(pageflip);
            previousScreen = currentScreen;
            currentScreen = SCREEN_CATCOLLECTION2;
        }
        else if (IsKeyPressed(KEY_C)) {
            PlaySound(pageflip);
            currentScreen = SCREEN_GAME;
        }
    }
    else if (currentScreen == SCREEN_CATCOLLECTION4) {
        if (IsKeyPressed(KEY_LEFT)) {
            PlaySound(pageflip);
            previousScreen = currentScreen;
            currentScreen = SCREEN_CATCOLLECTION3;
        }
        else if (IsKeyPressed(KEY_C)) {
            PlaySound(pageflip);
            currentScreen = SCREEN_GAME;
        }
    }
}

#endif  SCREEN_H