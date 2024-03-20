#pragma once

#include "AbstractParsingStrategy.h"

class DisplayEditsParsingStrategy : public AbstractParsingStrategy {
public:
	vector<string> parse(string input);
};