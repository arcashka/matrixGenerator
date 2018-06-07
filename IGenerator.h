#pragma once

#include <memory>

struct Matrix;

class IGenerator
{
public:
	virtual std::shared_ptr<Matrix> Generate(int size) = 0;
};
