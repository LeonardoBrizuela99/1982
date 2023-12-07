#include "rules.h"
#include"utils_manager/rectangleButton.h"



void drawRules(RectangleButton& backButton, Vector2 mouse)
{
    
    
    ClearBackground(BLACK);

    const int fontSize = 40;

    DrawRectangle((GetScreenWidth() / 2) - 300, 50, 600, 400, BLACK);

    DrawText("RULES", (GetScreenWidth() / 2) - 120, 70, 60, WHITE);

    DrawText("To move use the arrows.", 50, 150, fontSize, WHITE);
    DrawText("To shot press left click.", 50, 200, fontSize, WHITE);
    DrawText("Press ESC to pause the game.", 50, 250, fontSize, WHITE);
    DrawText("You only have 3 life.", 50, 310, fontSize, WHITE);

    backButton.pos.x = static_cast<float>(50);
    backButton.pos.y = static_cast<float>(GetScreenHeight() - 70);

    DrawRectangle(static_cast<int>(backButton.pos.x), static_cast<int>(backButton.pos.y), static_cast<int>(backButton.size.x), static_cast<int>(backButton.size.y), WHITE);

    DrawText("BACK",
        static_cast<int>(backButton.pos.x + 20),
        static_cast<int>(backButton.pos.y + 5),
        fontSize,
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