#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "AbstractFileVisitor.h"

using namespace std;

class LSCommand :public AbstractCommand {
public:
	AbstractFileSystem* abstractFileSystemPointer_;
	LSCommand(AbstractFileSystem* afsp);
	int execute(std::string metadata);
	void displayInfo();
};