#include "player.h"

Player CreatePlayer()
{
	Player player;
	player.rec.x = GetScreenWidth()/2;
	player.rec.y = 500;
	player.rec.width = 50;
	player.rec.height = 50;
	player.color = RED;
	player.speed = 100.0f;
	return player;
}

//Rectangle GetPlayer(Player& player)
//{
//	return Rectangle();
//}

void DrawPlayer(Player& player)
{
	DrawRectangle(player.rec.x,player.rec.y,player.rec.width,player.rec.height,player.color);

}

//void MovePlayer(Player& player)
//{
//}

void UpdatePlayer(Player& player)
{
	DrawPlayer(player);
}
