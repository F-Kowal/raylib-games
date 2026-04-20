#include <iostream>
#include <raylib.h>
#include "grid.h"

int main() 
{
	Color darkGrey = { 40, 40, 40, 255 };
	InitWindow(300, 600, "Tetris++");
	SetTargetFPS(60);

	Grid grid = Grid();
	grid.Print();

	while(WindowShouldClose() == false) 
	{
		BeginDrawing();
		ClearBackground(darkGrey);
		grid.Draw();

		EndDrawing();
	}

	CloseWindow();
}