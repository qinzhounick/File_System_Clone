#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

using namespace std;

class CatCommand :public AbstractCommand {
public:
	AbstractFileSystem* abstractFileSystemPointer_;
	CatCommand(AbstractFileSystem* afsp);
	int execute(std::string name);
	void displayInfo();
};