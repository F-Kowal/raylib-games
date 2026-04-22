#include <iostream>
#include <raylib.h>
#include "game.h"

int main() 
{
	Color darkGrey = { 40, 40, 40, 255 };
	InitWindow(300, 600, "Tetris++");
	SetTargetFPS(60);

	Game game = Game();

	while(WindowShouldClose() == false) 
	{
		BeginDrawing();
		ClearBackground(darkGrey);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}