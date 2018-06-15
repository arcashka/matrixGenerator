#pragma once

#include "Generator.h"

IGenerator* CreateGenerator() { return new Generator(); }
