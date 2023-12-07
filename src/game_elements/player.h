#pragma once

#include"raylib.h"
#include"bullet.h"
#include"enemy.h"
#include"utils_manager/utils.h"

struct Player
{ 
	Rectangle rec;
	Color color;
	float speed;
	Bullet bullets[MaxBullets];
};

Player CreatePlayer();
void DrawPlayer(Player& player);
void MovePlayer(Player& player);
void UpdatePlayer(Player& player, bool& isPaused,Enemy& enemy);
