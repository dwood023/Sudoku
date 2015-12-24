#include <vector>

namespace Utils {
	
	void shuffleVector(std::vector<int> &vectorToShuffle);

	int randInRange(int min, int max);

	int roundDownToMultiple(int roundee, int multiple);

	bool allEqualValue(std::vector<int> args, int value);

	std::vector<int> getSequence(int size, int increment);

	std::vector<int> getZeroesVector(int size);

	unsigned int factorial(int num);
	unsigned int getVectorProduct(const std::vector<int> vector);

};

