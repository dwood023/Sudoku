#ifndef GAME_GENERATOR_H
#define GAME_GENERATOR_H
#include "GameBoard.h"

class GameGenerator {
	 
	public:

		GameGenerator(GameBoard& board);
		vector2DInt getBoard();

	private:

		vector2DInt generatedBoard;
		vector2DInt xPool;
		vector2DInt yPool;
		vector2DInt blockPool;
		int blockSizeX;
		int blockSizeY;
		int boardSize;
		void populateBoard();
		void resetBlock(int blockNum);
		bool populateBlock(int blockNum);
};
#endif
