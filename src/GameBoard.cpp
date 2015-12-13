#include <math.h>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include "GameBoard.h"
#include "Utils.h"

GameBoard::GameBoard(int newBoardSize) {
	
	boardSize = newBoardSize;

	setBlockSize();

	board = getNewBoard();
}

void GameBoard::setBlockSize() {
	 
	int boardSqrt = sqrt(boardSize);

	if ((boardSqrt * boardSqrt) == boardSize) {
		blockSizeX = boardSqrt;
		blockSizeY = boardSqrt;
	}
	else 
		for (int i = boardSize / 2; i > 0; --i) {
			if(boardSize % i == 0) {
				blockSizeX = i;
				blockSizeY = boardSize / i;
				break;
			}
		}
	std::cout << blockSizeX << std::endl;
	std::cout << blockSizeY << std::endl;

}

vector2DInt GameBoard::getNewBoard() {

	vector2DInt newBoard(boardSize, Utils::getZeroesVector(boardSize)),
				blockPool(boardSize, Utils::getSequence(boardSize, 1));
	vector2DInt	xPool = blockPool,
				yPool = blockPool;

	constexpr int maxTries = 40;
	int blockFailures = 0;

	for (int blockNum = 0; blockNum < boardSize; ++blockNum) {
		 
		int xStartPos = blockNum * blockSizeX,
			yStartPos = 0,
			tries = 0;

		while (xStartPos >= boardSize) {
			xStartPos -= boardSize;
			yStartPos += blockSizeY;
		}

		for (int y = yStartPos; y < yStartPos + blockSizeY && tries <= maxTries; ++y) {

			for (int x = xStartPos; x < xStartPos + blockSizeX && tries <= maxTries; ++tries) {

				int rand = Utils::randInRange(0, boardSize);
				std::vector<int> poolSelections = { xPool[y][rand], yPool[x][rand], blockPool[blockNum][rand] };

				if (Utils::allEqualValue(poolSelections, rand + 1)) {

					std::cout << "blockNum = " << blockNum << " x = " << x << " y = " << y << std::endl;
					newBoard[x][y] = blockPool[blockNum][rand];
					blockPool[blockNum][rand] = 0, xPool[y][rand] = 0, yPool[x][rand] = 0, tries = 0;
					++x;

					printBoard(newBoard);
					
				}
				else if (tries >= maxTries) {
					for (int y = yStartPos, i = 0; y < yStartPos + blockSizeY; ++y) {
						for (int x = xStartPos; x < xStartPos + blockSizeX; ++x, ++i) {
							int num = newBoard[x][y];
							blockPool[blockNum][num - 1] = num;
							xPool[y][num - 1] = num;
							yPool[x][num - 1] = num;
						}
					}
					++blockFailures;
					--blockNum; // Roll back block and try again
				}
				if (blockFailures > 7) // 
					return getNewBoard();
			}
		}
	}

	return newBoard;
}

void GameBoard::printBoard(vector2DInt boardToPrint) {

	int size = boardToPrint.size();

	std::cout << std::endl;
	for (auto y = 0; y < size; ++y) {
		for (auto x = 0; x < size; ++x) {
			std::cout << boardToPrint[x][y] << " ";
			if ((((x + 1) % blockSizeY) == 0) && x != size - 1)
				std::cout << "| ";
		}
		std::cout << std::endl;
		if ((((y + 1) % blockSizeX) == 0) && y != size - 1) {
			for (int i = 0; i < size + 2; ++i)
				std::cout << "- ";
			std::cout << std::endl; 
		}
	}
}
