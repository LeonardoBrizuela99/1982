#pragma once

#include"raylib.h"
#include"bullet.h"
struct Player
{ 
	Rectangle rec;
	Color color;
	float speed;
	Bullet bullets[MaxBullets];
};

Player CreatePlayer();
//Rectangle GetPlayer(Player& player);
void DrawPlayer(Player& player);
void MovePlayer(Player& player);
void UpdatePlayer(Player& player, bool& isPaused);
