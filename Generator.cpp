#include "Generator.h"
#include "Matrix.h"

std::shared_ptr<Matrix> Generator::Generate(int size)
{
	return std::make_shared<Matrix>(
		Matrix
		{
			std::vector<double>{1, 3, 2, 7},
			std::vector<double>{5, 4},
			std::vector<int>   {0, 0, 0, 1, 2},
			std::vector<int>   {0, 0},
			std::vector<double>{32, 6, 11, 32}
		}
	);
};
