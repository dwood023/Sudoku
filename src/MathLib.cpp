#include <vector>
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

	int randInRange(const int min, const int max) {
		 
		return min + (rand() % max - min);

	}

	int roundDownToMultiple(int roundee, int multiple) {

		if (multiple == 0) return roundee;
		
		return roundee - (roundee % multiple);
	}
}
