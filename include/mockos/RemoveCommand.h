#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractFileVisitor.h"

using namespace std;

class RemoveCommand :public AbstractCommand {
public:
	AbstractFileSystem* abstractFileSystemPointer_;
	RemoveCommand(AbstractFileSystem* afsp);
	int execute(std::string metadata);
	void displayInfo();
};