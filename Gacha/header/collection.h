#include "raylib.h"

#ifndef COLLECTION_H
#define COLLECTION_H

void CatCollection(int randomIndex, bool& cat1, bool& cat2, bool& cat3, bool& cat4, bool& cat5) {
    if (randomIndex == 0) {
        cat1 = true;
    }
    else if (randomIndex == 1) {
        cat2 = true;
    }
    else if (randomIndex == 2) {
        cat3 = true;
    }
    else if (randomIndex == 3) {
        cat4 = true;
    }
    else if (randomIndex == 4) {
        cat5 = true;
    }
}


void Collection(float SCREEN_WIDTH, float SCREEN_HEIGHT, bool& cat1, bool& cat2, bool& cat3, bool& cat4, bool& cat5,
    Texture texture1, Texture texture2, Texture texture3, Texture texture4, Texture texture5) {
    if (cat1) {
        DrawTexture(texture1, (SCREEN_WIDTH / 2 - 473), SCREEN_HEIGHT / 2 - 320, WHITE);
    }
    if (cat2) {
        DrawTexture(texture2, (SCREEN_WIDTH / 2 - 120), SCREEN_HEIGHT / 2 - 320, WHITE);
    }
    if (cat3) {
        DrawTexture(texture3, (SCREEN_WIDTH / 2 + 224), SCREEN_HEIGHT / 2 - 320, WHITE);
    }
    if (cat4) {
        DrawTexture(texture4, (SCREEN_WIDTH / 2 - 305), SCREEN_HEIGHT / 2 + 8, WHITE);
    }
    if (cat5) {
        DrawTexture(texture5, (SCREEN_WIDTH / 2 + 50), SCREEN_HEIGHT / 2 + 8, WHITE);
    }
}

void Collection2(float SCREEN_WIDTH, float SCREEN_HEIGHT, bool& cat1, bool& cat2, bool& cat3,
    Texture texture1, Texture texture2, Texture texture3) {
    if (cat1) {
        DrawTexture(texture1, (SCREEN_WIDTH / 2 - 120), SCREEN_HEIGHT / 2 - 320, WHITE);
    }
    if (cat2) {
        DrawTexture(texture2, (SCREEN_WIDTH / 2 - 305), SCREEN_HEIGHT / 2 + 8, WHITE);
    }
    if (cat3) {
        DrawTexture(texture3, (SCREEN_WIDTH / 2 + 50), SCREEN_HEIGHT / 2 + 8, WHITE);
    }
}

#endif COLLECTION_H



