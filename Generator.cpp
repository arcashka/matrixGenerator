#include "Generator.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Matrix.h"
#include "source/solver/MatrixUtils.h"

std::shared_ptr<Matrix> Generator::Generate(int size, int sparseness, std::vector<double> & x)
{
	std::cout << "pew" << std::endl;
	std::vector<int>    ig;
	std::vector<int>    jg;
	std::vector<double> ggl;
	std::vector<double> di;

	int lowerTriangleElemNumber = (size / 2.0) * (size - 1);

	ig.reserve(size + 1);
	jg.reserve(lowerTriangleElemNumber);
	ggl.reserve(lowerTriangleElemNumber);
	di.reserve(size);

	std::srand(std::time(nullptr));

	int gglNum = 0;
	int count  = 0;
	double gglMult = 10.0;
	double diMult  = 1000.0;

	for(int i = 0; i < size; i++)
	{
		ig.push_back(count);
		for(int j = 0; j < i; j++, gglNum++)
		{
			if(gglNum % sparseness == 0)
			{
				ggl.push_back((double(std::rand()) / double(RAND_MAX)) * gglMult);
				jg.push_back(j);
				count++;
			}
		}
	}
	ig.push_back(count);

	for(int i = 0; i < size; i++)
		di.push_back((double(std::rand()) / double(RAND_MAX)) * diMult);

	std::vector<double> b;
	auto matrix = std::make_shared<Matrix>(
		Matrix {
			std::move(di),
			std::move(ggl),
			std::move(ig),
			std::move(jg),
			b
		}
	);

	b = matrix * x;
	matrix->b = std::move(b);

	return matrix;
};
