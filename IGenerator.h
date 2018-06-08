#pragma once

#include <memory>
#include <vector>

struct Matrix;

class IGenerator
{
public:
	virtual std::shared_ptr<Matrix> Generate(int size, int sparseness, std::vector<double> & x) = 0;
};
