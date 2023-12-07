#pragma once
#include "raylib.h"
#include "rectangleButton.h"
#include "game_elements/player.h"
#include "game_elements/enemy.h"

bool optionsCollision(Vector2 mouse, RectangleButton button);
bool CheckCollision(const Rectangle& rectA, const Rectangle& rectB);
bool CheckCollisionBullet(const Vector2& posA, const Vector2& sizeA, const Rectangle& rectB);