#pragma once
#include"raylib.h"
#include"utils_manager/rectangleButton.h"
#include"screen_manager/screenGameplay.h"
namespace game
{
	
	struct GameTextures
	{
	  
		Texture2D background;
		Texture2D bullet;
		Texture2D plane;
		Texture2D enemy;
	
	};

	struct GameRectangleButton
	{
		RectangleButton playButton ;
		RectangleButton multiplayerButton ;
		RectangleButton backButton ;
		RectangleButton rulesButton ;
		RectangleButton creditsButton ;
		RectangleButton exitButton;
		RectangleButton continueButton;
		RectangleButton restartButton ;

	};
	struct SoundsGame
	{
		Sound pause;
	};
	
	void RunGame();
}