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

	std::cout << "before loop\n";
	for (int i = 1; i <= boardSize; ++i) {
		std::cout << i << std::endl;
		possibleNumbers.push_back(i);
	}
	assert(boardSize == possibleNumbers.size());

	std::cout << "after loop\n";

	setBlockSize();

	populate();
}

void GameBoard::setBlockSize() {
	 
	int boardSqrt = sqrt(boardSize);

	if ((boardSqrt * boardSqrt) == boardSize)
		blockSize = {boardSqrt, boardSqrt};
	else 
		for (int i = boardSize / 2; i > 0; --i) {
			 
			if(boardSize % i == 0) {
				blockSize = {i, boardSize / i};
				break;
			}

		}
	std::cout << blockSize[0] << std::endl;
	std::cout << blockSize[1] << std::endl;

}
void GameBoard::populate() {

	std::vector<std::vector<int> > numPool;

	for (auto x = 0; x < boardSize; ++x)
		numPool.push_back(possibleNumbers);

	for (auto block = 0; block < boardSize; ++block) {
		 
		int xPosition = block * blockSize[0];
		int yPosition = 0;

		while (xPosition >= boardSize) {
			xPosition -= boardSize;
			yPosition += blockSize[1];
		}

		for (int y = yPosition; y < yPosition + blockSize[1]; ++y) {
			for (int x = xPosition; x < xPosition + blockSize[0]; ++x) {

				numPool[x][y] = block;

				std::cout << x << y << std::endl;
				 
			}
		}

	}

	for (auto y = 0; y < boardSize; ++y) {
		 
		std::cout << std::endl;
		for (auto x = 0; x < boardSize; ++x)
			std::cout << numPool[x][y] << " ";
	}
	
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
		if (possibleNumbers[i] != vec2check[i] && vec2check[i] != 0)
			return false;

	return true;

}
