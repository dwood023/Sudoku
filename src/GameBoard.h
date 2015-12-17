#ifndef GAME_BOARD_H
#define GAME_BOARD_H
#include <array>
#include <vector> 

typedef std::vector<std::vector<int>> vector2DInt;

class GameBoard {
	 
	public:

		GameBoard(int newBoardSize);
		int getBlockSizeY();
		int getBlockSizeX();
		int getBoardSize();
		void printBoard(vector2DInt board);

	private:

		int boardSize;

		int blockSizeX;
		int blockSizeY;

		vector2DInt board;

		vector2DInt getNewBoard();

		void setBlockSize();

		bool rollBackBlock(vector2DInt &board, int blockNum);
		bool validPlacement(unsigned int xIndex, unsigned int yIndex);
		bool validBlock(unsigned int xIndex, unsigned int yIndex);
		bool validy(unsigned int yIndex);
		bool validx(unsigned int xIndex);
		bool checkNoDuplicates(std::vector<int> vec2check);

};
#endif
