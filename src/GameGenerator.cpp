#include <iostream>
#include <vector>
#include "GameGenerator.h"
#include "GameBoard.h"
#include "Utils.h"

GameGenerator::GameGenerator(GameBoard& board)
:
	blockSizeY(board.getBlockSizeY()),
	blockSizeX(board.getBlockSizeX()),
	boardSize(board.getBoardSize()),
	generatedBoard(board.getBoardSize(), std::vector<int>(board.getBoardSize(), 0)),
	blockPool(board.getBoardSize(), std::vector<int>(Utils::getSequence(board.getBoardSize(), 1))),
	yPool(board.getBoardSize(), std::vector<int>(Utils::getSequence(board.getBoardSize(), 1))),
	xPool(board.getBoardSize(), std::vector<int>(Utils::getSequence(board.getBoardSize(), 1)))
{
	populateBoard();
}

void GameGenerator::populateBoard() {

	for (int blockNum = 0, blockTries = 0; blockNum < blockSizeX * blockSizeY; ++blockNum)
		while (!populateBlock(blockNum)) {
			resetBlock(blockNum);
			if (++blockTries > 3 && blockNum > 0) {
				--blockNum, blockTries = 0;
			}
		}
}

bool GameGenerator::populateBlock(int blockNum) {

	int xStartPos = blockNum * blockSizeX,
		yStartPos = 0;

	while (xStartPos >= boardSize) {
		xStartPos -= boardSize;
		yStartPos += blockSizeY;
	}

	int tries = 0;

	for (int y = yStartPos; y < yStartPos + blockSizeY; ++y) 
		for (int x = xStartPos; x < xStartPos + blockSizeX; ++tries) {

			int rand = Utils::randInRange(0, boardSize);

			if (blockPool[blockNum][rand] == rand + 1 && xPool[y][rand] == rand + 1 && yPool[x][rand] == rand +1) {

				generatedBoard[x][y] = rand + 1;
				blockPool[blockNum][rand] = 0, yPool[x][rand] = 0, xPool[y][rand] = 0, tries = 0;
				++x;
			}
			else if (tries > 18) {
				return false; 
			}
		}

	return true;
}

void GameGenerator::resetBlock(int blockNum) {

	int xStartPos = blockNum * blockSizeX,
		yStartPos = 0;

	while (xStartPos >= boardSize) {
		xStartPos -= boardSize;
		yStartPos += blockSizeY;
	}

	for (int y = yStartPos; y < yStartPos + blockSizeY; ++y) 
		for (int x = xStartPos; x < xStartPos + blockSizeX; ++x) {
				 
			int num = generatedBoard[x][y];

			if (num == 0) 
				return;

			generatedBoard[x][y] = 0;
			blockPool[blockNum][num -1] = num;
			xPool[y][num -1] = num;
			yPool[x][num -1] = num;
				
		}
}

vector2DInt GameGenerator::getBoard() {
	 return generatedBoard;
}
