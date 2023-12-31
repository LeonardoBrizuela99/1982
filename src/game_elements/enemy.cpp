#include"enemy.h"
#include "raylib.h"

Enemy CreateEnemy(Texture2D& texture)
{ 
    Enemy enemy;    
    enemy.rect.x = static_cast<float>( GetRandomValue(0, GetScreenWidth() /2));
    enemy.rect.y = 50; 
    enemy.rect.width = 30; 
    enemy.rect.height =30;
    enemy.color = RED;
    enemy.speed = 250;
    enemy.texture = texture;
    enemy.active = true;
    return enemy;
}

void UpdateEnemy(Enemy& enemy, bool& isPaused)
{
    if (!isPaused)
    {      
        enemy.rect.y += enemy.speed * GetFrameTime();

        if (enemy.rect.y > GetScreenHeight())
        {           
            ResetEnemy(enemy);
        }
    }
       
}

void DrawEnemy(Enemy& enemy)
{
   if (enemy.active)
   {
     //DrawRectangle(enemy.rect.x,enemy.rect.y,enemy.rect.width,enemy.rect.height, RED);
     DrawTexture(enemy.texture, static_cast<int>(enemy.rect.x), static_cast<int>(enemy.rect.y), enemy.color);
   }
}

void ResetEnemy(Enemy& enemy)
{  
    enemy.rect.x = static_cast<float>(GetRandomValue(0, GetScreenWidth() / 2));
    enemy.rect.y = -enemy.rect.height; 
    enemy.active = true; 
}