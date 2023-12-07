#include "screenCredits.h"

void drawCredits(RectangleButton& backButton,
    Vector2 mouse)
{
    ClearBackground(BLACK);

    const int fontSize = 20;

    DrawRectangle((GetScreenWidth() / 2) - 300, GetScreenHeight() / 2 - 200, 600, 400, BLACK);


  
    const int creditsHeight = 80;

    
    int creditsTextWidth = MeasureText("CREDITS", 60);

   
    DrawText("CREDITS", (GetScreenWidth() - creditsTextWidth) / 2, 20, 60, WHITE);

    
    int nameLeftOffset = 40; 
    DrawText("code: Leonardo Brizuela", nameLeftOffset, creditsHeight, fontSize, WHITE);
    DrawText("Parallax: https://opengameart.org/content/perfectly-seamless-island-background ", nameLeftOffset, creditsHeight + 120, fontSize, WHITE);
    DrawText("Ships and bullet: https://www.kenney.nl/assets/pixel-shmup", nameLeftOffset, creditsHeight + 170, fontSize, WHITE);
    DrawText("sound: https://freesound.org/people/MATRIXXX_/sounds/506546/", nameLeftOffset, creditsHeight + 250, fontSize, WHITE);
    DrawText("GamplayMusic:https://freesound.org/people/dkiller2204/sounds/423134/", nameLeftOffset, creditsHeight + 300, fontSize, WHITE);

    backButton.pos.x = 0;
    backButton.pos.y = static_cast<float>(GetScreenHeight() - backButton.size.y); 

    DrawRectangle(static_cast<int>(backButton.pos.x), static_cast<int>(backButton.pos.y), static_cast<int>(backButton.size.x), static_cast<int>(backButton.size.y), WHITE);

    DrawText("BACK",
        static_cast<int>(backButton.pos.x + 20),
        static_cast<int>(backButton.pos.y + 5),
        40,
        RED);

    if (optionsCollision(mouse, backButton))
    {
        backButton.isSelected = true;
        DrawRectangle(static_cast<int>(backButton.pos.x),
            static_cast<int>(backButton.pos.y),
            static_cast<int>(backButton.size.x),
            static_cast<int>(backButton.size.y),
            GRAY);

        DrawText("BACK",
            static_cast<int>(backButton.pos.x + 20),
            static_cast<int>(backButton.pos.y + 5),
            fontSize,
            RED);
    }
    else if (!optionsCollision(mouse, backButton))
    {
        backButton.isSelected = false;
    }
}