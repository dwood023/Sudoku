#include <vector>
#include <random>
#include <stdlib.h>
#include "MathLib.h"

namespace MathLib {

	void shuffleVector(std::vector<int> &vectorToShuffle) {

		for (auto i = vectorToShuffle.size() - 1; i > 0; --i) {

			unsigned int randIndex = MathLib::randInRange(0, i);

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
}
