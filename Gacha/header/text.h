#include "raylib.h"

#ifndef TEXT_H
#define TEXT_H
void Text(float& timer, bool& showText, Screen& currentScreen, int screenWidth, int screenHeight) {
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
                screenWidth / 2 - MeasureText("-Press ENTER to Start-", 64) / 2,
                screenHeight / 2 + 200, 64, WHITE);
        }
    }
    else if (currentScreen == SCREEN_HELP) {
        if (showText)
        {
            DrawText("-Press ENTER to Proceed-",
                screenWidth / 2 - MeasureText("-Press ENTER to Proceed-", 52) / 2,
                screenHeight / 2 + 320, 52, WHITE);
        }
    }

}

#endif TEXT_H
