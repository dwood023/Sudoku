#include <array>
#include <vector> 

class GameBoard {
	 
	public:

		GameBoard(int newBoardSize);

	private:

		int boardSize;

		std::array<int, 2> blockSize;

		std::vector<std::vector<int>> board;

		std::vector<int> possibleNumbers;

		void populate();

		void setBlockSize();

		bool validPlacement(unsigned int xIndex, unsigned int yIndex);
		bool validBlock(unsigned int xIndex, unsigned int yIndex);
		bool validy(unsigned int yIndex);
		bool validx(unsigned int xIndex);
		bool checkNoDuplicates(std::vector<int> vec2check);

};
