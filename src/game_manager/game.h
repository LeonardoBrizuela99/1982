#pragma once
#include"raylib.h"
#include"utils_manager/rectangleButton.h"
#include"screen_manager/screenGameplay.h"
namespace game
{
	
	struct GameTextures
	{
		
		  
			Texture2D background ;
	
	
	
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
		Sound jumpSound;
		Sound fallSound;
		Sound loseLife;
		Sound lose;
		Sound pause;
	};
	
	void RunGame();
}