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

		bool validPlacement(unsigned int rowIndex, unsigned int columnIndex);
		bool validBlock(unsigned int rowIndex, unsigned int columnIndex);
		bool validColumn(unsigned int columnIndex);
		bool validRow(unsigned int rowIndex);
		bool checkNoDuplicates(std::vector<int> vec2check);

};
