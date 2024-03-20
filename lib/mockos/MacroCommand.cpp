#include "mockos/MacroCommand.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* afsp) :
	abstractFileSystemPointer_(afsp), abstractParsingStrategyPointer_(nullptr) {}


int MacroCommand::execute(string name) {
	vector<string> inputs = abstractParsingStrategyPointer_->parse(name);

	int errorCheck = 0;
	//loop through command list to execute commands
	for (int i = 0; i < commandVector.size(); i++) {
		errorCheck = commandVector[i]->execute(inputs[i]);
		if (errorCheck) {
			return errorCheck;
		}
	}

	return success;
}

void MacroCommand::addCommand(AbstractCommand* ac) {
	commandVector.push_back(ac);

}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps) {
	abstractParsingStrategyPointer_ = aps;
}


void MacroCommand::displayInfo() {
	cout << "Macro executes multiple commands with the given input string." << endl;
}