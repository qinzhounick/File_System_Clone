#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"

using namespace std;

class MacroCommand :public AbstractCommand {
public:
	AbstractFileSystem* abstractFileSystemPointer_;
	//AbstractFileFactory* abstractFileFactoryPointer_;
	AbstractParsingStrategy* abstractParsingStrategyPointer_;
	vector<AbstractCommand*> commandVector;

	MacroCommand(AbstractFileSystem* afsp);
	int execute(string name);
	void displayInfo();
	void addCommand(AbstractCommand* ac);
	void setParseStrategy(AbstractParsingStrategy* aps);
};