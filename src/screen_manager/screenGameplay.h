#pragma once
#include "raylib.h"
#include "game_elements/player.h"
#include "game_elements/enemy.h"
#include "utils_manager/rectangleButton.h"
#include "utils_manager/utils.h"

enum class GameScreen
{
	MENU,
	GAMEPLAY,
	RULES,
	CREDITS,
	EXIT
};

void drawGame(Texture2D background, bool isPaused, bool isGameOver);