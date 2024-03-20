#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

using namespace std;

class DisplayCommand :public AbstractCommand {
public:
	AbstractFileSystem* abstractFileSystemPointer_;
	DisplayCommand(AbstractFileSystem* afsp);
	int execute(std::string name);
	void displayInfo();
};