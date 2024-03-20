#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"


using namespace std;

class CommandPrompt {
public:
	std::map<string, AbstractCommand*> pointerToCommandMap_;
	AbstractFileSystem* abstractFileSystemPointer_;
	AbstractFileFactory* abstractFileFactoryPointer_;
	CommandPrompt();
	//~CommandPrompt();
	void setFileSystem(AbstractFileSystem* afs);
	void setFileFactory(AbstractFileFactory* aff);
	int addCommand(std::string name, AbstractCommand* ac);
	int run();
protected:
	void listCommands();
	std::string prompt();

};