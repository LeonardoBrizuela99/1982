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
    MULTIPLAYER,
	RULES,
	CREDITS,
	EXIT
};

void drawGame(
    Texture2D background,
    Texture2D midground,
    Texture2D foreground,
    Texture2D tree,
    Texture2D bushTop,
    Texture2D bushDown,
    bool isPaused,
    bool isGameOver);