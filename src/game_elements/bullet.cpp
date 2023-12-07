#include "bullet.h"
#include"raymath.h"

void CreateBullets(Vector2 spawPositions, Bullet bullets[MaxBullets])
{
    Vector2 mousePosition = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {

        for (int i = 0; i < MaxBullets; i++) 
        {
            if (!bullets[i].active) 
            {
                bullets[i].position = { spawPositions };
                bullets[i].velocity = Vector2Normalize({ mousePosition.x - spawPositions.x, mousePosition.y - spawPositions.y });
                bullets[i].velocity.x *= 700;
                bullets[i].velocity.y *= 700;
                bullets[i].width = 10.0f;
                bullets[i].height = 15.0f;
                bullets[i].color = RAYWHITE;
                bullets[i].active = true;
                break;
            }
        }
    }
}


void UpadateBullets(Bullet bullets[MaxBullets])
{
    for (int i = 0; i < MaxBullets; i++) 
    {
        if (bullets[i].active)
        {
            bullets[i].position.x += bullets[i].velocity.x * GetFrameTime();
            bullets[i].position.y += bullets[i].velocity.y * GetFrameTime();

            if (bullets[i].position.x < 0 || bullets[i].position.x > 1024 ||
                bullets[i].position.y < 0 || bullets[i].position.y > 768) {
                bullets[i].active = false;
            }
            else
            {
                //DrawRectangle(bullets[i].position.x, bullets[i].position.y, bullets[i].width, bullets[i].height, bullets[i].color); 
                DrawTexture(bullets[i].texture, bullets[i].position.x, bullets[i].position.y , bullets[i].color);
            }
        }
    }
}

void DrawBullets(Bullet bullets[MaxBullets])
{
    for (int i = 0; i < MaxBullets; i++)
    {
        if (bullets[i].active)
        {
            if (bullets[i].position.x < 0 || bullets[i].position.x > 1024 ||
                bullets[i].position.y < 0 || bullets[i].position.y > 768) {
                bullets[i].active = false;
            }
            else
            {
               // DrawRectangle(bullets[i].position.x, bullets[i].position.y, bullets[i].width, bullets[i].height, bullets[i].color);
                DrawTexture(bullets[i].texture, bullets[i].position.x, bullets[i].position.y, bullets[i].color);
            }
        } 
    }
}
