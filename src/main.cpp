//#include"Game.h"
#include"raylib.h"
#include<iostream>
//#include"Menu.h"
using namespace std;

static void Init();
static void MainLoop();
static void Close();
void Update();
//void DrawPause();


const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGTH =  768;
const int meteorSpeed = 150;


 bool exitWindow = false;
 bool pause = false;
 bool salir = false;

namespace game
{
	void RunGame()
	{
		Init();
		MainLoop();
		Close();
	}
}

static void Init()
{
	InitWindow(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGTH), "ASTEROIDS");
	SetExitKey(KEY_NULL);
	//InitializeTexts();
	//ship = CreateShip();


}

 void MainLoop()
{
	while (!exitWindow)
	{
		while (!WindowShouldClose() && !salir)
		{
			//ScenesSwitch();
			exitWindow = true;
		}
	}
}

void Update()
{
		

}

 void Close()
{
	CloseWindow();
}

 void Draw()
{
	BeginDrawing();
	ClearBackground(RED);
	DrawRectangle(0, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));
	DrawRectangle(GetScreenWidth() - 5, 0, 5, GetScreenHeight(), Fade(WHITE, 1.0f));

	if (pause)
	{
		//DrawPause();
	}
	else
	{
		

	}

	EndDrawing();
}
 
 void GameLoop()
{
	if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_P))
	{
		pause = !pause;
		cout << "pause" << endl;
		cout << pause << endl;
		//DrawPause();
	}

	if (!pause)
	{
		Update();
	}
	else
	{
		//DrawPause();

		if (IsKeyPressed(KEY_R))
		{
			
			pause = false;
			
		}
		else if (IsKeyPressed(KEY_ESCAPE))
		{
			/*menu = MenuScenes::MainMenu;*/
			pause = false;
			
		}
	}

	Draw();
}



void UpdateMenu()
{
	/*CheckSinglePlayer();
	CheckInstructions();
	CheckCredits();
	CheckBack();
	CheckQuit();*/
}


void backMenu()
{
	if (IsKeyPressed(KEY_ESCAPE))
	{
		/*menu = MenuScenes::MainMenu;*/
	}
}



