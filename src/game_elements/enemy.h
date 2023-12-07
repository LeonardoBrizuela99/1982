#pragma once
#include "raylib.h"

struct Enemy
{
    Rectangle rect;
    Color color;
    float speed;
    bool active;
};

Enemy CreateEnemy();
void UpdateEnemy(Enemy& enemy, bool& isPaused);
void DrawEnemy(Enemy& enemy);
void ResetEnemy(Enemy& enemy);