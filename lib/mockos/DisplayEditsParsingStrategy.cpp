#include "mockos/DisplayEditsParsingStrategy.h"

using namespace std;

vector<string> DisplayEditsParsingStrategy::parse(string input) {
	istringstream iss(input);
	string fileName, catInput, dsInput, firstOption, secOption;

	iss >> fileName;

	catInput = fileName;
	dsInput = fileName;

	if (iss >> firstOption) {
		if (firstOption == "-a") {
			catInput += " " + firstOption;
		}
		else if (firstOption == "-d") {
			dsInput += " " + firstOption;
		}
	}

	if (iss >> secOption) {
		if (secOption == "-d") {
			dsInput += " " + secOption;
		}
	}

	vector<string> inputs;
	inputs.push_back(catInput);
	inputs.push_back(dsInput);

	return inputs;
}