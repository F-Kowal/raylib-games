#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveLeft();
	void MoveRight();
	void MoveDown();
	Grid grid;

private:
	std::vector<Block> blocks;
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	Block currentBlock;
	Block nextBlock;
};

#endif
