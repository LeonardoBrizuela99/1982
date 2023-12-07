#include "screenGameplay.h"
#include<iostream>

void drawGame(Texture2D background, bool isPaused, bool isGameOver)
{
    static float scrollingBack = 0.0f;   
    DrawTextureEx(background, Vector2{ 0, -scrollingBack }, 0.0f, 2.0f, WHITE);
    DrawTextureEx(background, Vector2{ 0, -background.height * 2 - scrollingBack }, 0.0f, 2.0f, WHITE);

    if (!isGameOver && !isPaused)
    {
        scrollingBack -= 100.0f * GetFrameTime();

        if (scrollingBack <= -background.height * 2) scrollingBack = 0;
    }
}