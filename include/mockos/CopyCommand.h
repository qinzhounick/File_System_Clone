#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

using namespace std;

class CopyCommand :public AbstractCommand {
public:
	AbstractFileSystem* abstractFileSystemPointer_;
	CopyCommand(AbstractFileSystem* afsp);
	int execute(std::string name);
	void displayInfo();
};