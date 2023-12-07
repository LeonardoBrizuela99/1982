#include "game.h"
#include "raylib.h"
#include "utils_manager/utils.h"
#include "screen_manager/screenGameplay.h"
#include "screen_manager/screenMenu.h"
#include "screen_manager/screenCredits.h"
#include "game_elements/enemy.h"
#include"screen_manager/rules.h"
#include<iostream>
#include"game_elements/player.h"
using namespace std;


namespace game
{

	void InitTextures(GameTextures& gameTextures);
	void InitSounds(SoundsGame& soundsGame);
	void InitButtons(GameRectangleButton& gameButtons);
	void GameScreenMenu(GameRectangleButton& gameButtons, GameScreen& currentScreen, Vector2& mouse);
	void GameScreenSingleplayer(SoundsGame& soundsGame, Player& player, Enemy& firstEnemy/*, Enemy& secondEnemy*/, bool& isPaused, bool& isGameOver, GameRectangleButton& gameButtons, GameTextures& gameTextures, GameScreen& currentScreen, Vector2 mouse);
	void GameScreenCredits(GameRectangleButton& gameButtons, GameScreen& currentScreen, Vector2& mouse);
	void GameScreenRules(GameRectangleButton& gameButtons, GameScreen& currentScreen, Vector2& mouse);
	void DeInitTextures(GameTextures& gameTextures);
	void DeInitSounds(SoundsGame& soundsGame);
	void PauseScreen(GameRectangleButton& gameButtons, Vector2& mouse, bool& isPaused);
	void GameOverScreen(GameRectangleButton& gameButtons, Vector2& mouse, bool& isGameOver, Player& player);
	
	
    
	static int fontSize = 40;


	 bool isGameRunning = true;
	
	void RunGame()
	{
		
       
		const int screenWidth = 1024;
		const int screenHeight = 768;

		bool isPaused = false;
		bool musicPaused = false;
	    bool isGameOver = false;
		InitWindow(screenWidth, screenHeight, "Flappy Bird");
		InitAudioDevice();
		Music music = LoadMusicStream("res/sounds/snowfall-final.mp3");
		Music musicGameplay = LoadMusicStream("res/sounds/music.mp3");
		PlayMusicStream(music);
		PlayMusicStream(musicGameplay);
		SoundsGame soundsGame;
		InitSounds(soundsGame);
		GameTextures gameTextures;
		InitTextures(gameTextures);
		GameRectangleButton gameButtons;
		InitButtons(gameButtons);
		Enemy firstEnemy = CreateEnemy(gameTextures.enemy);
		

		Player player = CreatePlayer(gameTextures.plane,gameTextures.bullet);
		
		
			SetExitKey(KEY_ESCAPE);

		GameScreen currentScreen = GameScreen::MENU;
	

		while (!WindowShouldClose() && isGameRunning)
		{

				
			BeginDrawing();
			ClearBackground(BLACK);
			Vector2 mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };
			
				switch (currentScreen)
				{
				case GameScreen::MENU:

					UpdateMusicStream(music);
					GameScreenMenu(gameButtons, currentScreen, mouse);
					if (IsKeyPressed(KEY_ESCAPE))
					{
					 isGameRunning = false;

					}
					break;					

				case GameScreen::GAMEPLAY:
					SetExitKey(NULL);

					UpdateMusicStream(musicGameplay);
					GameScreenSingleplayer(soundsGame,player,firstEnemy, isPaused, isGameOver, gameButtons, gameTextures, currentScreen, mouse);
					break;
				case GameScreen::RULES:
					SetExitKey(NULL);
					UpdateMusicStream(music);
					GameScreenRules(gameButtons, currentScreen, mouse);

					break;
				case GameScreen::CREDITS:
					SetExitKey(NULL);
					UpdateMusicStream(music);
					GameScreenCredits(gameButtons, currentScreen, mouse);
					
					break;
				case GameScreen::EXIT:
					isGameRunning = false;
					break;
				default:
					break;
				}
			
			
			EndDrawing();
		}
		
		UnloadMusicStream(music);
		UnloadMusicStream(musicGameplay);
		DeInitSounds(soundsGame);
		CloseAudioDevice();
		DeInitTextures(gameTextures);
		CloseWindow();
	}
	void InitTextures(GameTextures& gameTextures)
	{
		
		gameTextures.background = LoadTexture("res/textures/IslandsMap.png");
		gameTextures.plane = LoadTexture("res/textures/ship_player.png");
		gameTextures.bullet = LoadTexture("res/textures/bullet.png");
		gameTextures.enemy = LoadTexture("res/textures/ship_enemy.png");
		
	}
	void InitSounds(SoundsGame& soundsGame)
	{
		soundsGame.jumpSound=LoadSound("res/sounds/jumping.wav");
		soundsGame.fallSound=LoadSound("res/sounds/fall.wav");
		soundsGame.loseLife=LoadSound("res/sounds/loseLife.wav");
		soundsGame.lose=LoadSound("res/sounds/lose.wav");
		soundsGame.pause=LoadSound("res/sounds/pop.wav");

	}
	void DeInitTextures(GameTextures& gameTextures)
	{
		UnloadTexture(gameTextures.background);
		UnloadTexture(gameTextures.plane);
		UnloadTexture(gameTextures.enemy);
		UnloadTexture(gameTextures.bullet);
	
		
	}
	void DeInitSounds(SoundsGame& soundsGame)
	{
		UnloadSound(soundsGame.jumpSound);
		UnloadSound(soundsGame.fallSound);
		UnloadSound(soundsGame.loseLife);
		UnloadSound(soundsGame.lose);
		UnloadSound(soundsGame.pause);
	}
	void PauseScreen(GameRectangleButton& gameButtons, Vector2& mouse,bool& isPaused)
	{
		if (isPaused)
		{
			DrawRectangle((GetScreenWidth() / 2) - 300, GetScreenHeight() / 2 - 200, 600, 500, BLACK);

			DrawText("PAUSED", (GetScreenWidth() / 2) - 120, (GetScreenHeight() / 2) - 140, 60, WHITE);

			gameButtons.backButton.pos.x = static_cast<float>((GetScreenWidth() / 2) - 270);
			gameButtons.backButton.pos.y = static_cast<float>((GetScreenHeight() / 2) + 80);

			DrawRectangle(static_cast<int>(gameButtons.backButton.pos.x), static_cast<int>(gameButtons.backButton.pos.y), static_cast<int>(gameButtons.backButton.size.x), static_cast<int>(gameButtons.backButton.size.y), WHITE);

			DrawText("BACK",
				static_cast<int>(gameButtons.backButton.pos.x + 20),
				static_cast<int>(gameButtons.backButton.pos.y + 5),
				fontSize,
				RED);

			if (optionsCollision(mouse, gameButtons.backButton))
			{
				gameButtons.backButton.isSelected = true;
				DrawRectangle(static_cast<int>(gameButtons.backButton.pos.x),
					static_cast<int>(gameButtons.backButton.pos.y),
					static_cast<int>(gameButtons.backButton.size.x),
					static_cast<int>(gameButtons.backButton.size.y),
					GRAY);

				DrawText("BACK",
					static_cast<int>(gameButtons.backButton.pos.x + 20),
					static_cast<int>(gameButtons.backButton.pos.y + 5),
					fontSize,
					RED);
			}
			else if (!optionsCollision(mouse, gameButtons.backButton))
			{
				gameButtons.backButton.isSelected = false;
			}

			gameButtons.continueButton.pos.x = static_cast<float>((GetScreenWidth() / 2) + 50);
			gameButtons.continueButton.pos.y = static_cast<float>((GetScreenHeight() / 2) + 80);

			DrawRectangle(static_cast<int>(gameButtons.continueButton.pos.x),
				static_cast<int>(gameButtons.continueButton.pos.y),
				static_cast<int>(gameButtons.continueButton.size.x),
				static_cast<int>(gameButtons.continueButton.size.y),
				WHITE);

			DrawText("CONTINUE",
				static_cast<int>(gameButtons.continueButton.pos.x + 5),
				static_cast<int>(gameButtons.continueButton.pos.y + 5),
				fontSize,
				RED);

			if (optionsCollision(mouse, gameButtons.continueButton))
			{
				gameButtons.continueButton.isSelected = true;
				DrawRectangle(static_cast<int>(gameButtons.continueButton.pos.x),
					static_cast<int>(gameButtons.continueButton.pos.y),
					static_cast<int>(gameButtons.continueButton.size.x),
					static_cast<int>(gameButtons.continueButton.size.y),
					GRAY);

				DrawText("CONTINUE",
					static_cast<int>(gameButtons.continueButton.pos.x + 5),
					static_cast<int>(gameButtons.continueButton.pos.y + 5),
					fontSize,
					RED);
			}
			else if (!optionsCollision(mouse, gameButtons.continueButton))
			{
				gameButtons.continueButton.isSelected = false;
			}

			gameButtons.restartButton.pos.x = static_cast<float>((GetScreenWidth() / 2) - 100);
			gameButtons.restartButton.pos.y = static_cast<float>((GetScreenHeight() / 2) + 200);

			DrawRectangle(static_cast<int>(gameButtons.restartButton.pos.x),
				static_cast<int>(gameButtons.restartButton.pos.y),
				static_cast<int>(gameButtons.restartButton.size.x),
				static_cast<int>(gameButtons.restartButton.size.y),
				WHITE);

			DrawText("RESTART",
				static_cast<int>(gameButtons.restartButton.pos.x + 10),
				static_cast<int>(gameButtons.restartButton.pos.y + 10),
				fontSize,
				RED);

			if (optionsCollision(mouse, gameButtons.restartButton))
			{
				gameButtons.restartButton.isSelected = true;
				DrawRectangle(static_cast<int>(gameButtons.restartButton.pos.x),
					static_cast<int>(gameButtons.restartButton.pos.y),
					static_cast<int>(gameButtons.restartButton.size.x),
					static_cast<int>(gameButtons.restartButton.size.y),
					GRAY);

				DrawText("RESTART",
					static_cast<int>(gameButtons.restartButton.pos.x + 10),
					static_cast<int>(gameButtons.restartButton.pos.y + 10),
					fontSize,
					RED);
			}
			else if (!optionsCollision(mouse, gameButtons.restartButton))
			{
				gameButtons.restartButton.isSelected = false;
			}
		}
	}
	void GameOverScreen(GameRectangleButton& gameButtons, Vector2& mouse, bool& isGameOver, Player &player)
	{
		if (isGameOver)
		{
			
		
		
			DrawRectangle((GetScreenWidth() / 2) - 300, GetScreenHeight() / 2 - 200, 600, 500, BLACK);
			

			DrawText("GAME OVER", (GetScreenWidth() / 2) - 200, (GetScreenHeight() / 2) - 140, 60, WHITE);

			gameButtons.backButton.pos.x = static_cast<float>((GetScreenWidth() / 2) - 270);
			gameButtons.backButton.pos.y = static_cast<float>((GetScreenHeight() / 2) + 80);

			DrawRectangle(static_cast<int>(gameButtons.backButton.pos.x), static_cast<int>(gameButtons.backButton.pos.y), static_cast<int>(gameButtons.backButton.size.x), static_cast<int>(gameButtons.backButton.size.y), WHITE);
	
			DrawText("BACK",
				static_cast<int>(gameButtons.backButton.pos.x + 20),
				static_cast<int>(gameButtons.backButton.pos.y + 5),
				fontSize,
				RED);

			if (optionsCollision(mouse, gameButtons.backButton))
			{
				gameButtons.backButton.isSelected = true;
				DrawRectangle(static_cast<int>(gameButtons.backButton.pos.x),
					static_cast<int>(gameButtons.backButton.pos.y),
					static_cast<int>(gameButtons.backButton.size.x),
					static_cast<int>(gameButtons.backButton.size.y),
					GRAY);

				DrawText("BACK",
					static_cast<int>(gameButtons.backButton.pos.x + 20),
					static_cast<int>(gameButtons.backButton.pos.y + 5),
					fontSize,
					RED);
			}
			else if (!optionsCollision(mouse, gameButtons.backButton))
			{
				gameButtons.backButton.isSelected = false;
			}
			gameButtons.restartButton.pos.x = static_cast<float>((GetScreenWidth() / 2) + 50);
			gameButtons.restartButton.pos.y = static_cast<float>((GetScreenHeight() / 2) + 80);
			
			DrawRectangle(static_cast<int>(gameButtons.restartButton.pos.x),
				static_cast<int>(gameButtons.restartButton.pos.y),
				static_cast<int>(gameButtons.restartButton.size.x),
				static_cast<int>(gameButtons.restartButton.size.y),
				WHITE);

			DrawText("RESTART",
				static_cast<int>(gameButtons.restartButton.pos.x + 5),
				static_cast<int>(gameButtons.restartButton.pos.y + 5),
				fontSize,
				RED);

			if (optionsCollision(mouse, gameButtons.restartButton))
			{
				gameButtons.restartButton.isSelected = true;
				DrawRectangle(static_cast<int>(gameButtons.restartButton.pos.x),
					static_cast<int>(gameButtons.restartButton.pos.y),
					static_cast<int>(gameButtons.restartButton.size.x),
					static_cast<int>(gameButtons.restartButton.size.y),
					GRAY);

				DrawText("RESTART",
					static_cast<int>(gameButtons.restartButton.pos.x + 5),
					static_cast<int>(gameButtons.restartButton.pos.y + 5),
					fontSize,
					RED);
			}
			else if (!optionsCollision(mouse, gameButtons.restartButton))
			{
				gameButtons.restartButton.isSelected = false;
				InitPlane(player);
			}
			
		}


	}

	
	void InitButtons(GameRectangleButton& gameButtons)
	{
		Vector2 buttonSize = { 220, 50 };

		gameButtons.playButton = {};
		gameButtons.multiplayerButton = {};
		gameButtons.backButton = {};
		gameButtons.rulesButton = {};
		gameButtons.creditsButton = {};
		gameButtons.exitButton = {};
		gameButtons.continueButton = {};
		gameButtons.restartButton = {};

		gameButtons.playButton = initButton(gameButtons.playButton, buttonSize);
		gameButtons.multiplayerButton = initButton(gameButtons.multiplayerButton, buttonSize);
		gameButtons.rulesButton = initButton(gameButtons.rulesButton, buttonSize);
		gameButtons.restartButton = initButton(gameButtons.restartButton, buttonSize);
		gameButtons.creditsButton = initButton(gameButtons.creditsButton, buttonSize);
		gameButtons.exitButton = initButton(gameButtons.exitButton, buttonSize);
		gameButtons.continueButton = initButton(gameButtons.continueButton, buttonSize);
		gameButtons.backButton = initButton(gameButtons.backButton, buttonSize);
	

	}
	void GameScreenMenu(GameRectangleButton& gameButtons, GameScreen& currentScreen, Vector2& mouse)
	{
		
		drawMenu(gameButtons.playButton, gameButtons.rulesButton, gameButtons.creditsButton, gameButtons.exitButton, mouse);
		
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.playButton.isSelected == true)
		{
			currentScreen = GameScreen::GAMEPLAY;
			
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.rulesButton.isSelected == true)
		{
			currentScreen = GameScreen::RULES;
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.creditsButton.isSelected == true)
		{
			currentScreen = GameScreen::CREDITS;
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.exitButton.isSelected == true)
		{
			currentScreen = GameScreen::EXIT;
		}
	}
	
	void GameScreenSingleplayer(SoundsGame& soundsGame, Player& player, Enemy& firstEnemy,bool &isPaused, bool& isGameOver, GameRectangleButton& gameButtons, GameTextures& gameTextures, GameScreen& currentScreen, Vector2 mouse)
	{
		if (isPaused)
		{
			static bool pauseSound = false;
			if (!pauseSound)
			{
				PlaySound(soundsGame.pause);
				pauseSound = true;
			}
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.backButton.isSelected == true)
			{
				InitPlane(player);
				ResetEnemy(firstEnemy);
				/*InitBird(bird);
				ResetWall(firstWall, secondWall);*/

				pauseSound = false;
				currentScreen = GameScreen::MENU;
				isPaused = false;
			}
			else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.continueButton.isSelected == true)
			{
				isPaused = false;
				pauseSound = false;
			}
			else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.restartButton.isSelected == true)
			{
				pauseSound =false;
				InitPlane(player);
				ResetEnemy(firstEnemy);
				isPaused = false;

			}

		}
		if (isGameOver)
		{
			
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.backButton.isSelected == true)
			{
				
				currentScreen = GameScreen::MENU;
				isGameOver = false;
				
				InitPlane(player);
				ResetEnemy(firstEnemy);

			}
			else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.restartButton.isSelected == true)
			{
				//bird.score = bird.score;
				isGameOver = false;
			
				InitPlane(player);
				ResetEnemy(firstEnemy);


			}
		}
		if (IsKeyPressed(KEY_ESCAPE))
		{
			isPaused=!isPaused;
			PlaySound(soundsGame.pause);
		}
		else
		{
			drawGame(gameTextures.background,isPaused, isGameOver);
			UpdatePlayer(player,isPaused, firstEnemy, isGameOver);
			UpdateEnemy(firstEnemy, isPaused);
			DrawEnemy(firstEnemy);	
			PauseScreen(gameButtons, mouse, isPaused);
			GameOverScreen(gameButtons,mouse,isGameOver, player);
			//DrawText(TextFormat(" Score: %i", bird.score), 0, 0, 40, WHITE);
			//cout << bird.score << endl;
			
		}	
	}
	void GameScreenRules(GameRectangleButton& gameButtons, GameScreen& currentScreen, Vector2& mouse)
	{
		drawRules(gameButtons.backButton, mouse);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.backButton.isSelected == true || IsKeyPressed(KEY_ESCAPE))
		{
			currentScreen = GameScreen::MENU;
			

		}
	}
	void GameScreenCredits(GameRectangleButton& gameButtons, GameScreen& currentScreen, Vector2& mouse)
	{
	
		drawCredits(gameButtons.backButton, mouse);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && gameButtons.backButton.isSelected == true|| IsKeyPressed(KEY_ESCAPE))
		{
			currentScreen = GameScreen::MENU;
		}
	}
	
}



