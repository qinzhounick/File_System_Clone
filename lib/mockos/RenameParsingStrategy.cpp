#include "mockos/RenameParsingStrategy.h"

using namespace std;

vector<string> RenameParsingStrategy::parse(string input) {
	istringstream iss(input);
	string fileName, copyFileName, copyInput, removeInput;

	iss >> fileName;
	iss >> copyFileName;

	copyInput = fileName + " " + copyFileName;
	removeInput = fileName;
	
	vector<string> inputs;
	inputs.push_back(copyInput);
	inputs.push_back(removeInput);

	return inputs;
}