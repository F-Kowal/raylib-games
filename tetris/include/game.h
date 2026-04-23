#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include "blocks.h"

class Game
{
public:
	Game();
    ~Game();
    void Draw();
	void HandleInput();
	void MoveDown(bool isSoftDrop);
	bool gameOver;
	int score;
	Music music;

private:
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	std::vector<Block> blocks;
	bool IsBlockOutside();
	void RotateBlock();
	void MoveLeft();
	void MoveRight();
	void LockBlock();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
	bool BlockFits();
	Grid grid;
	Block currentBlock;
	Block nextBlock;
	// Sound rotateSound;
	Sound clearSound;
	Sound dropSound;
	Sound gameOverSound;
};

#endif
