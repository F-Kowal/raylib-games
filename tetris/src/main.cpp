#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"

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
	Color grey = {40, 40, 40, 255};
	InitWindow(500, 620, "Tetris++");
	SetTargetFPS(60);

	Font font = LoadFontEx("assets/fonts/NineteenEightySeven.ttf", 64, 0, 0);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		bool fastDrop = IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN);
		double interval = fastDrop ? 0.05 : 0.3;

		if (EventTrigered(interval))
		{
			game.MoveDown(fastDrop);
		}

		BeginDrawing();
		ClearBackground(grey);
		DrawTextEx(font, "Tetris++", {320, 15}, 26, 2, WHITE);
		DrawTextEx(font, "Score", {350, 80}, 22, 2, WHITE);
		DrawTextEx(font, "Next", {365, 220}, 22, 2, WHITE);

		if (game.gameOver)
		{
			DrawTextEx(font, "GAME OVER", {320, 490}, 19, 2, WHITE);
			DrawTextEx(font, "Press any key", {325, 525}, 13, 2, WHITE);
			DrawTextEx(font, "to restart", {345, 542}, 13, 2, WHITE);
		}

		char scoreText[10];
		sprintf(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 22, 2);

		DrawRectangleRounded({320, 110, 170, 60}, 0.3, 6, scoreGrey);
		DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 130}, 22, 2, WHITE);
		DrawRectangleRounded({320, 250, 170, 150}, 0.3, 6, scoreGrey);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}