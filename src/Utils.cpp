#include <vector>
#include <random>
#include <stdlib.h>
#include "Utils.h"

namespace Utils {

	void shuffleVector(std::vector<int> &vectorToShuffle) {

		for (auto i = vectorToShuffle.size() - 1; i > 0; --i) {

			unsigned int randIndex = Utils::randInRange(0, i);

			auto buffer = vectorToShuffle[i];

			vectorToShuffle[i] = vectorToShuffle[randIndex];
			vectorToShuffle[randIndex] = buffer;

		}

	};

	int randInRange(int min, int max) {
		 
		std::random_device randDevice;
		std::mt19937 twister(randDevice());
		
		std::uniform_real_distribution<> range(min, max);

		return range(twister); 
	}

	int roundDownToMultiple(int roundee, int multiple) {

		if (multiple == 0) return roundee;
		
		return roundee - (roundee % multiple);
	}

	bool allEqualValue(std::vector<int> args, int value) {
		for (int i : args)
			if (i != value) return false;
		return true;
	}

	std::vector<int> getSequence(int size, int increment) {
		 std::vector<int> sequence;
		 for (int i = 1; i <= size; i += increment)
			 sequence.push_back(i);
		 return sequence;
	}

	std::vector<int> getZeroesVector(int size) {
		 std::vector<int> zeroesVector;
		 for (int i = 0; i < size; ++i)
			 zeroesVector.push_back(0);
		 return zeroesVector;
	}

	unsigned int factorial(int num) {
		if (num == 1) return num;
		else return num * factorial(num - 1);
	}

	unsigned int getVectorProduct(const std::vector<int> vector) {
		int product = 1;
		for (int element : vector)
			product *= element;
		return product;
	}

}

