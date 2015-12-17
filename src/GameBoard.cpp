#include <math.h>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include "GameBoard.h"
#include "GameGenerator.h"
#include "Utils.h"

GameBoard::GameBoard(int newBoardSize) {
	
	boardSize = newBoardSize;

	setBlockSize();

	board = getNewBoard();

	printBoard(board);
}

void GameBoard::setBlockSize() {
	 
	int boardSqrt = sqrt(boardSize);

	if ((boardSqrt * boardSqrt) == boardSize) {
		blockSizeX = boardSqrt;
		blockSizeY = boardSqrt;
	}
	else 
		for (int i = boardSize / 2; i > 0; --i)
			if(boardSize % i == 0) {
				blockSizeX = i;
				blockSizeY = boardSize / i;
				break;
			}
}

vector2DInt GameBoard::getNewBoard() {

	GameGenerator gameGen(*this);

	return gameGen.getBoard();
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

int GameBoard::getBoardSize() { return boardSize; }
int GameBoard::getBlockSizeX() { return blockSizeX; }
int GameBoard::getBlockSizeY() { return blockSizeY; }
