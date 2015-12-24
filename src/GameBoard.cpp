#include <math.h>
#include <vector>
#include <iostream>
#include <set>
#include "GameBoard.h"
#include "GameGenerator.h"
#include "Utils.h"

GameBoard::GameBoard(int newBoardSize) 
: boardSize(newBoardSize)
{
	

	setBlockSize();

	board = getNewBoard();

	printBoard(board);
}

inline void GameBoard::setBlockSize() {
	 
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

bool GameBoard::validBoard() {
	for (int i = 0; i < boardSize; ++i)
		if (!validBlock(i) || !validY(i) || !validX(i)) return false;
	return true;
}

bool GameBoard::validBlock(int blockNum) {

		int xStartPos = blockNum * blockSizeX,
			yStartPos = 0;

		while (xStartPos >= boardSize) {
			xStartPos -= boardSize;
			yStartPos += blockSizeY;
		}

		std::set<int> blockSet;

		for (int y = yStartPos; y < yStartPos + blockSizeY; ++y) 
			for (int x = xStartPos; x < xStartPos + blockSizeX; ++x) 
				blockSet.insert(board[x][y]);

		return (blockSet.size() == boardSize);
}

bool GameBoard::validX(int xNum) {
	std::set<int> xSet(board[xNum].begin(), board[xNum].end());
	return (xSet.size() == boardSize);
}

bool GameBoard::validY(int yNum) {
	std::set<int> ySet;
	for (int x = 0; x < boardSize; ++x)
		ySet.insert(board[x][yNum]);
	 
	return (ySet.size() == boardSize);
}

int GameBoard::getBoardSize() { return boardSize; }
int GameBoard::getBlockSizeX() { return blockSizeX; }
int GameBoard::getBlockSizeY() { return blockSizeY; }
