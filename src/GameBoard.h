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
		inline void setBlockSize();
		bool validBoard();
		bool validBlock(int blockNum);
		bool validY(int yNum);
		bool validX(int xNum);

};
#endif
