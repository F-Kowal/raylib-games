#include "grid.h"
#include "colors.h"
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