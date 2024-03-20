#include "mockos/RemoveCommand.h"

RemoveCommand::RemoveCommand(AbstractFileSystem* afsp) :
	abstractFileSystemPointer_(afsp) {}


int RemoveCommand::execute(std::string name) {
	return abstractFileSystemPointer_->deleteFile(name);
}

void RemoveCommand::displayInfo() {
	cout << "RemoveCommand removes a file from the file system. Usage: rm <filename>" << endl;
}