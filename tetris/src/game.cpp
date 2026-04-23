#include "game.h"
#include <random>
#include <ctime>

Game::Game()
{
	srand(time(NULL));

	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}	

	int randomIndex = rand() % blocks.size();

	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);

	return block;
}

std::vector<Block> Game::GetAllBlocks()
{
	return { LBlock(), JBlock(),IBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Draw()
{
	grid.Draw();
	currentBlock.Draw();
}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();

	if (keyPressed == KEY_A || keyPressed == KEY_LEFT)
	{
		MoveLeft();
	}

	if (keyPressed == KEY_D || keyPressed == KEY_RIGHT)
	{
		MoveRight();
	}

	if (keyPressed == KEY_W || keyPressed == KEY_UP)
	{
		RotateBlock();
	}

	if (keyPressed == KEY_S || keyPressed == KEY_DOWN)
	{
		MoveDown();
	}
}

void Game::MoveLeft()
{
	currentBlock.Move(0, -1);
	if (IsBlockOutside() || BlockFits() == false)
	{
		currentBlock.Move(0, 1);
	}
}

void Game::MoveRight()
{
	currentBlock.Move(0, 1);
	if (IsBlockOutside() || BlockFits() == false)
	{
		currentBlock.Move(0, -1);
	}
}

void Game::MoveDown()
{
	currentBlock.Move(1, 0);
	if (IsBlockOutside() || BlockFits() == false)
	{
		currentBlock.Move(-1, 0);
		LockBlock();
	}
}

bool Game::IsBlockOutside()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();

	for (Position item : tiles)
	{
		if (grid.IsCellOutside(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}

void Game::RotateBlock()
{
	currentBlock.Rotate();
	if (IsBlockOutside() || BlockFits() == false)
	{
		currentBlock.UndoRotation();
	}
}

void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	nextBlock = GetRandomBlock();
}

bool Game::BlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.IsCellEmpty(item.row, item.column) == false)
		{
			return false;
		}
	}
	return true;
}
