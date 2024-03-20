#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "PasswordProxy.h"

using namespace std;

class TouchCommand :public AbstractCommand {
public:
	AbstractFileSystem* abstractFileSystemPointer_;
	AbstractFileFactory* abstractFileFactoryPointer_;
	TouchCommand(AbstractFileSystem* afsp, AbstractFileFactory* aff);
	int execute(std::string name);
	void displayInfo();
};