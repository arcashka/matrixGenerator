#pragma once

#include <memory>

#include "Matrix.h"

class IGenerator
{
public:
	std::shared_ptr<Matrix> Generate(int size);
};
