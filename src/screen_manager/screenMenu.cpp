#include "screenMenu.h"
#include"game_manager/game.h"

//using namespace game;

void drawMenu(	RectangleButton& playButton,
              	RectangleButton& multiplayerButton,
				RectangleButton& rulesButton,
				RectangleButton& creditsButton,
				RectangleButton& exitButton,
				Vector2 mouse)
{
	

	ClearBackground(BLACK);

	const int fontSize = 40;

	DrawText("1982", (GetScreenWidth() / 2) - 200, (GetScreenHeight() / 2 - 300), 60, WHITE);

	DrawText("Version 1.0", GetScreenWidth() - 120, GetScreenHeight() - 30, 20, WHITE);

	multiplayerButton.pos.x = (GetScreenWidth() / 2) - (multiplayerButton.size.x / 2);
	multiplayerButton.pos.y = static_cast<float>(GetScreenHeight() / 2-113) - (multiplayerButton.size.y);

	DrawRectangle(static_cast<int>(multiplayerButton.pos.x),
		static_cast<int>(multiplayerButton.size.x),
		static_cast<int>(multiplayerButton.pos.y),
		static_cast<int>(multiplayerButton.size.y),
		WHITE);

	DrawText("MULTIPLAYER",
		static_cast<int>(multiplayerButton.pos.x ),
		static_cast<int>(multiplayerButton.pos.y + 5),
		30,
		RED);

	playButton.pos.x = (GetScreenWidth() / 2) - (playButton.size.x / 2);
	playButton.pos.y = static_cast<float>(GetScreenHeight() / 2) - (playButton.size.y);

	DrawRectangle(	static_cast<int>(playButton.pos.x), 
					static_cast<int>(playButton.pos.y),
					static_cast<int>(playButton.size.x),
					static_cast<int>(playButton.size.y),
					WHITE);

	DrawText("PLAY",
		static_cast<int>(playButton.pos.x + 20),
		static_cast<int>(playButton.pos.y + 5),
		fontSize,
		RED);

	rulesButton.pos.x = (GetScreenWidth() / 2) - (rulesButton.size.x / 2);
	rulesButton.pos.y = static_cast<float>(GetScreenHeight() / 2) - (rulesButton.size.y - 60);

	DrawRectangle(	static_cast<int>(rulesButton.pos.x),
					static_cast<int>(rulesButton.pos.y),
					static_cast<int>(rulesButton.size.x),
					static_cast<int>(rulesButton.size.y),
					WHITE);

	DrawText(	"RULES",
				static_cast<int>(rulesButton.pos.x + 20),
				static_cast<int>(rulesButton.pos.y + 5),
				fontSize,
				RED);

	creditsButton.pos.x = (GetScreenWidth() / 2) - (creditsButton.size.x / 2);
	creditsButton.pos.y = static_cast<float>(GetScreenHeight() / 2) - (creditsButton.size.y - 120);

	DrawRectangle(	static_cast<int>(creditsButton.pos.x),
					static_cast<int>(creditsButton.pos.y),
					static_cast<int>(creditsButton.size.x),
					static_cast<int>(creditsButton.size.y),
					WHITE);

	DrawText(	"CREDITS",
				static_cast<int>(creditsButton.pos.x + 20),
				static_cast<int>(creditsButton.pos.y + 5),
				fontSize,
				RED);

	exitButton.pos.x = (GetScreenWidth() / 2) - (exitButton.size.x / 2);
	exitButton.pos.y = static_cast<float>(GetScreenHeight() / 2) - (exitButton.size.y - 180);

	DrawRectangle(	static_cast<int>(exitButton.pos.x),
					static_cast<int>(exitButton.pos.y),
					static_cast<int>(exitButton.size.x),
					static_cast<int>(exitButton.size.y),
					WHITE);

	DrawText(	"EXIT",
				static_cast<int>(exitButton.pos.x + 20),
				static_cast<int>(exitButton.pos.y + 5),
				fontSize,
				RED);

	if (optionsCollision(mouse, multiplayerButton))
	{
		multiplayerButton.isSelected = true;
		DrawRectangle(static_cast<int>(multiplayerButton.pos.x),
			static_cast<int>(multiplayerButton.pos.y),
			static_cast<int>(multiplayerButton.size.x),
			static_cast<int>(multiplayerButton.size.y),
			GRAY);

		DrawText("MULTIPLAYER",
			static_cast<int>(multiplayerButton.pos.x ),
			static_cast<int>(multiplayerButton.pos.y + 5),
			30,
			RED);
	}
	else if (!optionsCollision(mouse, multiplayerButton))
	{
		multiplayerButton.isSelected = false;
	}

	if (optionsCollision(mouse, playButton))
	{
		playButton.isSelected = true;
		DrawRectangle(	static_cast<int>(playButton.pos.x),
						static_cast<int>(playButton.pos.y),
						static_cast<int>(playButton.size.x),
						static_cast<int>(playButton.size.y),
						GRAY);

		DrawText(	"PLAY",
					static_cast<int>(playButton.pos.x + 20),
					static_cast<int>(playButton.pos.y + 5),
					fontSize,
					RED);
	}
	else if (!optionsCollision(mouse, playButton))
	{
		playButton.isSelected = false;
	}

	if (optionsCollision(mouse, rulesButton))
	{
		rulesButton.isSelected = true;
		DrawRectangle(	static_cast<int>(rulesButton.pos.x),
						static_cast<int>(rulesButton.pos.y),
						static_cast<int>(rulesButton.size.x),
						static_cast<int>(rulesButton.size.y),
						GRAY);

		DrawText(	"RULES",
					static_cast<int>(rulesButton.pos.x + 20),
					static_cast<int>(rulesButton.pos.y + 5),
					fontSize,
					RED);
	}
	else if (!optionsCollision(mouse, rulesButton))
	{
		rulesButton.isSelected = false;
	}

	if (optionsCollision(mouse, creditsButton))
	{
		creditsButton.isSelected = true;
		DrawRectangle(	static_cast<int>(creditsButton.pos.x),
						static_cast<int>(creditsButton.pos.y),
						static_cast<int>(creditsButton.size.x),
						static_cast<int>(creditsButton.size.y),
						GRAY);

		DrawText(	"CREDITS",
					static_cast<int>(creditsButton.pos.x + 20),
					static_cast<int>(creditsButton.pos.y + 5),
					fontSize,
					RED);
	}
	else if (!optionsCollision(mouse, creditsButton))
	{
		creditsButton.isSelected = false;
	}

	if (optionsCollision(mouse, exitButton))
	{
		exitButton.isSelected = true;
		DrawRectangle(	static_cast<int>(exitButton.pos.x),
						static_cast<int>(exitButton.pos.y),
						static_cast<int>(exitButton.size.x),
						static_cast<int>(exitButton.size.y),
						GRAY);

		DrawText(	"EXIT",
					static_cast<int>(exitButton.pos.x + 20),
					static_cast<int>(exitButton.pos.y + 5),
					fontSize,
					RED);
	}
	else if (!optionsCollision(mouse, exitButton))
	{
		exitButton.isSelected = false;
	}
}

//void GameScreenMenu(GameRectangleButton& gameButtons, GameScreen& currentScreen, Vector2& mouse)
//{
//
//	drawMenu(gameButtons.playButton, gameButtons.multiplayerButton, gameButtons.rulesButton, gameButtons.creditsButton, gameButtons.exitButton, mouse);
//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.multiplayerButton.isSelected == true)
//	{
//		currentScreen = GameScreen::MULTIPLAYER;
//	}
//	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.playButton.isSelected == true)
//	{
//		currentScreen = GameScreen::GAMEPLAY;
//
//	}
//	else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.rulesButton.isSelected == true)
//	{
//		currentScreen = GameScreen::RULES;
//	}
//	else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.creditsButton.isSelected == true)
//	{
//		currentScreen = GameScreen::CREDITS;
//	}
//	else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.exitButton.isSelected == true)
//	{
//		currentScreen = GameScreen::EXIT;
//	}
//}