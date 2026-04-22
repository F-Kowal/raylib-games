#include <iostream>
#include <raylib.h>
#include "game.h"

double lastUpdateTime = 0;

bool EventTrigered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main() 
{
	Color darkGrey = { 40, 40, 40, 255 };
	InitWindow(300, 600, "Tetris++");
	SetTargetFPS(60);

	Game game = Game();

	while(WindowShouldClose() == false) 
	{
		game.HandleInput();
		if (EventTrigered(0.3))
		{
			game.MoveDown(); // tetromino falling
		}
		BeginDrawing();
		ClearBackground(darkGrey);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}