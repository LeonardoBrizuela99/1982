#include "player.h"

Player CreatePlayer()
{
	Player player;
	player.rec.x = GetScreenWidth()/2;
	player.rec.y = 500;
	player.rec.width = 50;
	player.rec.height = 50;
	player.color = RED;
	player.speed = 400.0f;
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

void MovePlayer(Player& player)
{
	
	if (IsKeyDown(KEY_UP) && player.rec.y > 0)
	{
		player.rec.y -= player.speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_DOWN) && player.rec.y < GetScreenHeight() - 50)
	{
		player.rec.y += player.speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_LEFT) && player.rec.x > 0)
	{
		player.rec.x -= player.speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_RIGHT) && player.rec.x < GetScreenWidth() - 50)
	{
		player.rec.x += player.speed * GetFrameTime();
	}
	
	CreateBullets({ (player.rec.x+25),player.rec.y}, player.bullets);
}

void UpdatePlayer(Player& player, bool& isPaused)
{
	if (!isPaused)
	{
		MovePlayer(player);
		UpadateBullets(player.bullets);
	}

	DrawBullets(player.bullets);
	DrawPlayer(player);	
}
