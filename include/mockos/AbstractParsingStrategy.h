#pragma once

#include "AbstractFile.h"

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string input) = 0;
};