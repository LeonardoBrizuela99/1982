#pragma once

#include"raylib.h"
struct Player
{ 
	Rectangle rec;
	Color color;
	float speed;
};

Player CreatePlayer();
//Rectangle GetPlayer(Player& player);
void DrawPlayer(Player& player);
//void MovePlayer(Player& player);
void UpdatePlayer(Player& player);
