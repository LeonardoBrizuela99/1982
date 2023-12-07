#pragma once
#include"raylib.h"
//#include"game_manager/game.h"
struct Bullet 
{
    Vector2 position;
    Vector2 velocity;
    float height;
    float width;
    Color color;
    bool active;
    Texture2D texture;
   
};
const int MaxBullets = 100;
void UpadateBullets(Bullet bullets[MaxBullets]);
void CreateBullets(Vector2 spawPositions, Bullet bullets[MaxBullets]);
void DrawBullets(Bullet bullets[MaxBullets]);
