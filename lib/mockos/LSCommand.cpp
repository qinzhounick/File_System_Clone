#include "mockos/LSCommand.h"
#include "mockos/MetadataDisplayVisitor.h"

LSCommand::LSCommand(AbstractFileSystem* afsp) :
	abstractFileSystemPointer_(afsp) {}


int LSCommand::execute(std::string metadata) {
	//If -m was NOT entered
	if (metadata == "") {
		//Iterate through all files in the sytsem
		set<string> systemFileNames = abstractFileSystemPointer_->getFileNames();
		set<string>::iterator it = systemFileNames.begin();

		while (it != systemFileNames.end()) {
			cout << left << setw(20) << *it;
			it++;
			//Printing second number if applicable
			if (it != systemFileNames.end()) {
				cout << left << setw(20) << *it;
				it++;
			}
			cout << endl;
		}
		return success;
	} 
	//IF -m WAS entered
	else if(metadata == "-m"){
		//Iterate through all files in the sytsem
		set<string> systemFileNames = abstractFileSystemPointer_->getFileNames();
		set<string>::iterator it = systemFileNames.begin();
		AbstractFileVisitor* metadataFileVisitor = new MetadataDisplayVisitor();

		//if file is visited using ls -m for the first time,
		//  the second time calling ls -m would make currentFilePointer be nullptr 
		//  because file already opened
		while (it != systemFileNames.end()) {
			AbstractFile* currentFilePointer = abstractFileSystemPointer_->openFile(*it);
			currentFilePointer->accept(metadataFileVisitor);
			abstractFileSystemPointer_->closeFile(currentFilePointer);
			it++;

		}
		return success;
	}
	//If neither of the above was entered
	else {
		cout << "Error! Incorrect usage." << endl;
		LSCommand::displayInfo();
		return lsCommandFail;
	}
}

void LSCommand::displayInfo() {
	cout << "ls prints out all files in the current File Factory. You can optionally include '-m' to include file metadata." << endl;
}