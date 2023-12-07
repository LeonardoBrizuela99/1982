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
	int life;
	Texture2D texture;
	Texture2D bulletTexture;
	Bullet bullets[MaxBullets];
};

Player CreatePlayer(Texture2D& texture, Texture2D& bullet);
Player InitPlane(Player& player);
Player resetPlane(Player& player);
void DrawPlayer(Player& player);
void MovePlayer(Player& player);
void UpdatePlayer(Player& player, bool& isPaused,Enemy& enemy,bool& isGameOver);
