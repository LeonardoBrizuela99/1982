#include "player.h"

Player CreatePlayer(Texture2D& texture, Texture2D& bullet)
{
	Player player;
	player.rec.x = static_cast<float>(GetScreenWidth()/2);
	player.rec.y = 500;
	player.rec.width = 50;
	player.rec.height = 50;
	player.color = RAYWHITE;
	player.speed = 400.0f;
	player.texture = texture;
	player.bulletTexture = bullet;
	player.life = 3;
	return player;
}

Player InitPlane(Player& player)
{

	player.rec.x = static_cast<float>(GetScreenWidth() / 2);
	player.rec.y = 500;
	player.rec.width = 50;
	player.rec.height = 50;
	player.color = RAYWHITE;
	player.speed = 400.0f;
	player.life = 3;
	return player;
}

Player resetPlane(Player& player)
{
		
		player.rec.x = static_cast<float>( GetScreenWidth() / 2);
		player.rec.y = 500;
		player.rec.width = 50;
		player.rec.height = 50;
		player.color = RAYWHITE;
		player.speed = 400.0f;
		player.life = player.life;
		return player;
	
}
void DrawPlayer(Player& player)
{
	//DrawRectangle(player.rec.x,player.rec.y,player.rec.width,player.rec.height,player.color);
	DrawTexture(player.texture, static_cast<int>(player.rec.x), static_cast<int>(player.rec.y), player.color);

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

void UpdatePlayer(Player& player, bool& isPaused,Enemy& enemy, bool& isGameOver)
{
	if (isGameOver==false)
	{
		if (!isPaused)
		{
			MovePlayer(player);
			UpadateBullets(player.bullets);
			UpdateEnemy(enemy, isPaused);

			if (CheckCollision(player.rec, enemy.rect)) {

				player.rec.x = static_cast<float>(GetScreenWidth() / 2);
				player.rec.y = 500;
				player.life -= 1;
				ResetEnemy(enemy);

				if (player.life <= 0)
				{
					isGameOver = true;
					InitPlane(player);
					ResetEnemy(enemy);
				}

			}

			for (int i = 0; i < MaxBullets; ++i)
			{
				player.bullets[i].texture = player.bulletTexture;
				if (player.bullets[i].active) {
					if (CheckCollisionBullet(player.bullets[i].position, { player.bullets[i].width, player.bullets[i].height }, enemy.rect)) {

						player.bullets[i].active = false;
						ResetEnemy(enemy);

					}
				}
			}
		}

		DrawEnemy(enemy);
		DrawBullets(player.bullets);
		DrawPlayer(player);
	}

}
