#include <math.h>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include "GameBoard.h"
#include "MathLib.h"

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

	vector2DInt newBoard(boardSize, getZeroesVector(boardSize)),
				blockPool(boardSize, getPossibleNumbers());
	vector2DInt	xPool = blockPool,
				yPool = blockPool;

	int rand,
		tries = 0,
		xStartPos, yStartPos = 0;

	constexpr int maxTries = 40;

	for (int blockNum = 0; blockNum < boardSize; ++blockNum) {
		 
		xStartPos = blockNum * blockSizeX;
		yStartPos = 0;
		tries = 0;

		while (xStartPos >= boardSize) {
			xStartPos -= boardSize;
			yStartPos += blockSizeY;
		}

		for (int y = yStartPos; y < yStartPos + blockSizeY && tries <= maxTries; ++y) {

			for (int x = xStartPos; x < xStartPos + blockSizeX && tries <= maxTries; ++tries) {

				rand = MathLib::randInRange(0, boardSize);
				std::cout << tries << std::endl;

				if (xPool[y][rand] == rand + 1 && yPool[x][rand] == rand + 1 && blockPool[blockNum][rand] == rand + 1) {

					std::cout << "blockNum = " << blockNum << " x = " << x << " y = " << y << std::endl;
					newBoard[x][y] = blockPool[blockNum][rand];
					blockPool[blockNum][rand] = 0, xPool[y][rand] = 0, yPool[x][rand] = 0, tries = 0;
					++x;

					printBoard(newBoard);
					
				}
				else if (tries >= maxTries) {
					for (int y = yStartPos, i = 0; y < yStartPos + blockSizeY; ++y) {
						for (int x = xStartPos; x < xStartPos + blockSizeX; ++x, ++i) {
							xPool[y][x] = i + 1;
							yPool[x][y] = i + 1;
							blockPool[blockNum][i] = i + 1;
						}
					}
					std::cout << "trying block " << blockNum << " again" << std::endl;
					--blockNum; // Roll back block and try again
				}
			}
		}
	}

	return newBoard;
}

bool GameBoard::populateBlock(vector2DInt &board, int blockNum) {
	 
}

bool GameBoard::validPlacement(unsigned int x, unsigned int y) {
	 
	return validx(x) && validy(y) && validBlock(x, y);

}
bool GameBoard::validx(unsigned int xIndex) {

	for (int y = 0; y < boardSize; ++y) {
		
		if (board[xIndex][y] != 0) {
			for(int comparisony; comparisony < boardSize; ++comparisony) {

				if (board[xIndex][y] == board[xIndex][comparisony] && comparisony != y) {
					return false;
				}
			}
		}
	}
	return true;
}

bool GameBoard::validy(unsigned int yIndex) {

	for (int x = 0; x < boardSize; ++x) {
		
		if (board[x][yIndex] != 0) {

			for(int comparisonx; comparisonx < boardSize; ++comparisonx) {

				if (board[x][yIndex] == board[comparisonx][yIndex] && comparisonx != x) {
					return false;
				}
			}
		}
	}
	return true;
}

bool GameBoard::validBlock(unsigned int xIndex, unsigned int yIndex) {


	int startx = MathLib::roundDownToMultiple(xIndex, 3);
	int starty = MathLib::roundDownToMultiple(yIndex, 3);

	std::vector<int> blockNumbers;
	
	for (int x = startx; x < startx + 3; ++x) {
		 
		for (int y = starty; y < starty + 3; ++y) 
			blockNumbers[x + y] = board[x][y];
	}

	std::sort(blockNumbers.begin(), blockNumbers.end());

	return checkNoDuplicates(blockNumbers);

}

bool GameBoard::checkNoDuplicates(std::vector<int> vec2check) {
	 
	std::sort(vec2check.begin(), vec2check.end());

	for (int i = 0; i < 9; ++i) 
		if (getPossibleNumbers()[i] != vec2check[i] && vec2check[i] != 0)
			return false;

	return true;

}

void GameBoard::printBoard(vector2DInt boardToPrint) {

	int size = boardToPrint.size();

	std::cout << std::endl;
	for (auto y = 0; y < size; ++y) {
		for (auto x = 0; x < size; ++x)
			std::cout << boardToPrint[x][y] << " ";
		std::cout << std::endl;
	}
}

std::vector<int> GameBoard::getPossibleNumbers() {
	std::vector<int> possibleNumbers;

	for (int i = 1; i <= boardSize; ++i)
		possibleNumbers.push_back(i);

	return possibleNumbers;
}

std::vector<int> GameBoard::getZeroesVector(int size) {
	std::vector<int> zeroesVector;
	for (int i = 0; i < size; ++i)
		zeroesVector.push_back(0);
	return zeroesVector;
}

vector2DInt GameBoard::expandVectorTo2D(std::vector<int> vectorToExpand, int timesToExpand) {
	 
	vector2DInt expandedVector;

	for (auto x = 0; x < timesToExpand; ++x) {
		expandedVector.push_back(vectorToExpand);
	}

	return expandedVector;

}
