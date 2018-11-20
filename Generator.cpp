#include "Generator.h"

#include <ctime>

#include "source/LinearSystem.h"
#include "source/utils/MatrixUtils.h"

std::shared_ptr<LinearSystem> Generator::Generate(int size, int sparseness, std::vector<float>& x)
{
	std::vector<int>    ig;
	std::vector<int>    jg;
	std::vector<float> ggl;
	std::vector<float> di;

	const int lowerTriangleElemNumber = (size / 2.0) * (size - 1);

	ig.reserve(size + 1);
	jg.reserve(lowerTriangleElemNumber);
	ggl.reserve(lowerTriangleElemNumber);
	di.reserve(size);

	std::srand(std::time(nullptr));

	int gglNum = 0;
	int count  = 0;
	float gglMult = 1.0;
	float diMult  = 10000.0;

	for(int i = 0; i < size; i++)
	{
		ig.push_back(count);
		for(int j = 0; j < i; j++, gglNum++)
		{
			if(gglNum % sparseness == 0)
			{
				ggl.push_back((float(std::rand()) / float(RAND_MAX)) * gglMult);
				jg.push_back(j);
				count++;
			}
		}
	}
	ig.push_back(count);

	for(int i = 0; i < size; i++)
		di.push_back((float(std::rand()) / float(RAND_MAX)) * diMult);

	auto matrix = Matrix{ std::move(di), std::move(ggl), std::move(ig), std::move(jg) };

	std::vector<float> b = matrix * x;
	auto system = std::make_shared<LinearSystem>(LinearSystem{ std::move(matrix), std::move(b) });

	return system;
};
