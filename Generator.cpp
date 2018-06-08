#include "Generator.h"

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Matrix.h"
#include "source/solver/MatrixUtils.h"

std::shared_ptr<Matrix> Generator::Generate(int size, int sparseness, std::vector<double> & x)
{
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
	double gglMult = 10.0;
	double diMult  = 1000.0;

	for(int i = 0; i < size; i++)
	{
		int count = 0;
		ig.push_back(gglNum);
		for(int j = 0; j < i; j++, gglNum++)
		{
			std::cout << i << " " << gglNum << std::endl;
			if(gglNum % sparseness == 0)
			{
				std::cout << "in" << std::endl;
				ggl.push_back((double(std::rand()) / double(RAND_MAX)) * gglMult);
				jg.push_back(j);
				count++;
			}
		}
	}
	std::cout << "pew" << std::endl;

	for(int i = 0; i < size; i++)
		di.push_back((double(std::rand()) / double(RAND_MAX)) * diMult);

	std::cout << "pew";
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

	std::cout << "di" << std::endl;
	for(auto a : matrix->di)
		std::cout << a << " ";
	std::cout << std::endl;

	std::cout << "ggl" << std::endl;
	for(auto a : matrix->ggl)
		std::cout << a << " ";
	std::cout << std::endl;

	std::cout << "ig" << std::endl;
	for(auto a : matrix->ig)
		std::cout << a << " ";
	std::cout << std::endl;

	std::cout << "jg" << std::endl;
	for(auto a : matrix->jg)
		std::cout << a << " ";
	std::cout << std::endl;

	return matrix;
};
