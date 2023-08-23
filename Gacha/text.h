#include "raylib.h"

#ifndef TEXT_H
#define TEXT_H
void Text(float& timer, bool& showText, Screen& currentScreen, const int SCREEN_WIDTH, const int SCREEN_HEIGHT) {
    timer += GetFrameTime() * 1000; // Convert from seconds to milliseconds

    // Toggle text visibility every half a second (500 milliseconds)
    if (timer >= 500)
    {
        showText = !showText;
        timer = 0;
    }

    if (currentScreen == SCREEN_MENU) {
        if (showText)
        {
            DrawText("-Press Enter to Start-",
                SCREEN_WIDTH / 2 - MeasureText("-Press ENTER to Start-", 64) / 2,
                SCREEN_HEIGHT / 2 + 200, 64, WHITE);
        }
    }
    else if (currentScreen == SCREEN_HELP) {
        if (showText)
        {
            DrawText("-Press ENTER to Proceed-",
                SCREEN_WIDTH / 2 - MeasureText("-Press ENTER to Proceed-", 52) / 2,
                SCREEN_HEIGHT / 2 + 320, 52, WHITE);
        }
    }

}

void TextCounter(int& pull_counter, int SCREEN_WIDTH) {
    DrawText(("Pity Counter: " + std::to_string(pull_counter)).c_str(),
        SCREEN_WIDTH - MeasureText("Pity Counter :    ", 32), 10, 32, WHITE);
}

void RarityText(const int SCREEN_WIDTH, const int SCREEN_HEIGHT, Screen& currentScreen,
    bool& prompt_common, bool& prompt_S, bool& prompt_SS, bool& prompt_SSS) {

    if (prompt_common) {
        DrawText("'COMMON' RARITY CAT",
            SCREEN_WIDTH / 2 - MeasureText("'COMMON' RARITY CAT", 64) / 2,
            SCREEN_HEIGHT / 2 + 200, 64, GRAY);
    }
    else if (prompt_S) {
        DrawText("'S' RARITY CAT",
            SCREEN_WIDTH / 2 - MeasureText("'S' RARITY CAT", 64) / 2,
            SCREEN_HEIGHT / 2 + 200, 64, BLUE);
    }
    else if (prompt_SS) {
        DrawText("'SS' RARITY CAT",
            SCREEN_WIDTH / 2 - MeasureText("'SS' RARITY CAT", 64) / 2,
            SCREEN_HEIGHT / 2 + 200, 64, PURPLE);
    }
    else if (prompt_SSS) {
        DrawText("'SSS' RARITY CAT",
            SCREEN_WIDTH / 2 - MeasureText("'SSS' RARITY CAT", 64) / 2,
            SCREEN_HEIGHT / 2 + 200, 64, GOLD);
    }

}

void RarityPromptToggle(bool& prompt_common, bool& prompt_S, bool& prompt_SS, bool& prompt_SSS) {
    prompt_common = false;
    prompt_S = false;
    prompt_SS = false;
    prompt_SSS = false;
}

#endif TEXT_H
