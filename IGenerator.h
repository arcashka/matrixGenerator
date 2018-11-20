#pragma once

#include <memory>
#include <vector>

struct LinearSystem;

class IGenerator
{
public:
	virtual std::shared_ptr<LinearSystem> Generate(int size, int sparseness, std::vector<float> & x) = 0;
};
