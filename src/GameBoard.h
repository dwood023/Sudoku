#include <array>
#include <vector> 

class GameBoard {
	 
	public:

		GameBoard();

	private:

		int boardSize;

		std::vector<std::vector<int>> board;

		std::vector<int> possibleNumbers;

		void populate();

		bool validPlacement(unsigned int rowIndex, unsigned int columnIndex);
		bool validBlock(unsigned int rowIndex, unsigned int columnIndex);
		bool validColumn(unsigned int columnIndex);
		bool validRow(unsigned int rowIndex);
		bool checkNoDuplicates(std::vector<int> vec2check);

};
