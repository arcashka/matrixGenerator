#pragma once

#include <memory>

#include "IGenerator.h"

struct Matrix;

class Generator : public IGenerator
{
public:
	Generator() {};
	std::shared_ptr<Matrix> Generate(int size, int sparseness, std::vector<double> & x) override;
};
