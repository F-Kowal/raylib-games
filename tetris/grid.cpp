#include "grid.h"
#include <iostream>

Grid::Grid() 
{
	numRows = 20;
	numColumns = 10;
	cellSize = 30; // pixels
	Initialize();
	colors = GetCellColors();
}

void Grid::Initialize() 
{
	for (int row = 0; row < numRows; row++) 
	{
		for (int column = 0; column < numColumns; column++) 
		{
			grid[row][column] = 0;
		}
	}
}

void Grid::Print()
{
	for (int  row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			std::cout << grid[row][column] << " ";
		}

		std::cout << std::endl;
	}
}

std::vector<Color> Grid::GetCellColors()
{
	Color grey = { 30, 30, 30, 255 };
	Color red = { 255, 155, 190, 255 };
	Color orange = { 255, 200, 140, 255 };
	Color yellow = { 249, 255, 149, 255 };
	Color green = { 155, 255, 166, 255 };
	Color cyan = { 129, 243, 255, 255 };
	Color blue = { 61, 118, 255, 255 };
	Color purple = { 153, 134, 255, 255 };

	return { grey, red, orange, yellow, green, cyan, blue, purple };
}

void Grid::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numColumns; column++)
		{
			int cellValue = grid[row][column];
			DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize-1, cellSize-1, colors[cellValue]);
		}
	}
}