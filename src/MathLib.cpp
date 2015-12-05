#include <vector>
#include <stdlib.h>
#include "MathLib.h"

namespace MathLib {

	void shuffleVector(std::vector<int> &vectorToShuffle, const int startPoint) {

		for (auto i = startPoint; i < vectorToShuffle.size(); i++) {

			unsigned int randIndex = MathLib::randInRange((i), (vectorToShuffle.size() - 1));

			auto buffer = vectorToShuffle[i];

			vectorToShuffle[i] = vectorToShuffle[randIndex];
			vectorToShuffle[randIndex] = buffer;

		}

	};

	int randInRange(const int min, const int max) {
		 
		return rand() % max + min;

	}

	int roundDownToMultiple(int roundee, int multiple) {

		if (multiple == 0) return roundee;
		
		return roundee - (roundee % multiple);
	}
}
