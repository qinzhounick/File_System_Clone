#include "mockos/CopyCommand.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* afsp) :
	abstractFileSystemPointer_(afsp) {}


int CopyCommand::execute(std::string name) {
	istringstream iss(name);
	string fileName, copyFileName;
	iss >> fileName;

	//Check to make sure that file exists
	AbstractFile* filePointer = abstractFileSystemPointer_->openFile(fileName);
	if (filePointer == nullptr) {
		abstractFileSystemPointer_->closeFile(filePointer);
		return fileNotFound;
	}

	//Check to see if argument number is right
	if (!(iss >> copyFileName)) {
		abstractFileSystemPointer_->closeFile(filePointer);
		return incorrectArgument;
	}


	AbstractFile* copyFilePointer = filePointer->clone(copyFileName);
	if (copyFilePointer == nullptr) {
		abstractFileSystemPointer_->closeFile(filePointer);
		return errorCopyCreate;
	}

	if (abstractFileSystemPointer_->addFile(copyFilePointer->getName(), copyFilePointer) != success) {
		abstractFileSystemPointer_->closeFile(filePointer);
		return errorCopyAdd;
	}

	abstractFileSystemPointer_->closeFile(filePointer);
	return success;
}

void CopyCommand::displayInfo() {
	cout << "Copy command copies an existing file info into a new file with a different name. Using cp 'filename.txt copyfilename' copies the info stored in 'filename.txt' and put it into 'copyfilename.txt' " << endl;
}