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
		for (int i = boardSize / 2; i > 0; --i)
			if(boardSize % i == 0)
				blockSize = {i, boardSize / i};
	std::cout << blockSize[0] << std::endl;

}
void GameBoard::populate() {

	std::vector<int> shuffledPossibleNumbers(possibleNumbers);

	std::cout << "sad";


	for (int row = 0; row < boardSize; ++row) {

		MathLib::shuffleVector(shuffledPossibleNumbers, 0);

		board[row] = shuffledPossibleNumbers;
	}

	for (int row = 0; row < boardSize; ++row) {

		for (int column = 0; column < boardSize;) {

			if (validBlock(row, column) && validColumn(column))
				column++;
			else
				MathLib::shuffleVector(board[row], column);

		}

	}
}

bool GameBoard::validPlacement(unsigned int row, unsigned int column) {
	 
	return validRow(row) && validColumn(column) && validBlock(row, column);

}
bool GameBoard::validRow(unsigned int rowIndex) {

	for (int column = 0; column < boardSize; ++column) {
		
		if (board[rowIndex][column] != 0) {
			for(int comparisonColumn; comparisonColumn < boardSize; ++comparisonColumn) {

				if (board[rowIndex][column] == board[rowIndex][comparisonColumn] && comparisonColumn != column) {
					return false;
				}
			}
		}
	}
	return true;
}

bool GameBoard::validColumn(unsigned int columnIndex) {

	for (int row = 0; row < boardSize; ++row) {
		
		if (board[row][columnIndex] != 0) {

			for(int comparisonRow; comparisonRow < boardSize; ++comparisonRow) {

				if (board[row][columnIndex] == board[comparisonRow][columnIndex] && comparisonRow != row) {
					return false;
				}
			}
		}
	}
	return true;
}

bool GameBoard::validBlock(unsigned int rowIndex, unsigned int columnIndex) {


	int startRow = MathLib::roundDownToMultiple(rowIndex, 3);
	int startCol = MathLib::roundDownToMultiple(columnIndex, 3);

	std::vector<int> blockNumbers;
	
	for (int row = startRow; row < startRow + 3; ++row) {
		 
		for (int column = startCol; column < startCol + 3; ++column) 
			blockNumbers[row + column] = board[row][column];
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
