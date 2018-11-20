#pragma once

#include "IGenerator.h"

struct LinearSystem;

class Generator : public IGenerator
{
public:
	Generator() {};
	std::shared_ptr<LinearSystem> Generate(int size, int sparseness, std::vector<float>& x) override;
};
