#include <array>
#include <vector> 

typedef std::vector<std::vector<int>> vector2DInt;

class GameBoard {
	 
	public:

		GameBoard(int newBoardSize);

	private:

		int boardSize;

		int blockSizeX;
		int blockSizeY;

		vector2DInt board;

		vector2DInt getNewBoard();

		void setBlockSize();

		bool populateBlock(vector2DInt &board, int blockNum);
		std::vector<int> getPossibleNumbers();
		std::vector<int> getZeroesVector(int size);
		vector2DInt expandVectorTo2D(std::vector<int> vectorToExpand, int timesToExpand);
		bool validPlacement(unsigned int xIndex, unsigned int yIndex);
		bool validBlock(unsigned int xIndex, unsigned int yIndex);
		bool validy(unsigned int yIndex);
		bool validx(unsigned int xIndex);
		bool checkNoDuplicates(std::vector<int> vec2check);
		void printBoard(vector2DInt board);

};
