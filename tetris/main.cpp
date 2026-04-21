#include <iostream>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main() 
{
	Color darkGrey = { 40, 40, 40, 255 };
	InitWindow(300, 600, "Tetris++");
	SetTargetFPS(60);

	Grid grid = Grid();
	grid.Print();

	LBlock block = LBlock();

	while(WindowShouldClose() == false) 
	{
		BeginDrawing();
		ClearBackground(darkGrey);
		grid.Draw();
		block.Draw();
		EndDrawing();
	}

	CloseWindow();
}