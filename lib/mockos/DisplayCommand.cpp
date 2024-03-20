#include "mockos/DisplayCommand.h"
#include "mockos/BasicDisplayVisitor.h"

DisplayCommand::DisplayCommand(AbstractFileSystem* afsp) :
	abstractFileSystemPointer_(afsp) {}


int DisplayCommand::execute(std::string name) {
	istringstream iss(name);
	string fileName;
	iss >> fileName;

	//Check to make sure that file exists
	bool fileExists = false;
	set<string> fileNames = abstractFileSystemPointer_->getFileNames();
	//Make iterator towards beginning of set
	set<string>::iterator it = fileNames.begin();
	//Iterate through set to see if file exists
	while (it != fileNames.end()) {
		if (*it == fileName) {
			fileExists = true;
		}
		it++;
	}

	if (!fileExists) {
		return fileNotFound;
	}


	//Check to see if there is another parameter
	string parameter;
	bool formatted = true;
	if (iss >> parameter) {
		//If parameter is -d, print unformatted data
		if (parameter == "-d") {
			formatted = false;
		}
		else {
			return incorrectArgument;
		}
	}

	//THIS IS ALWAYS NULLPTR, BECAUSE IT IS ALREADY OPEN
	//IDK HOW TO GET POINTER FOR FILE???
	// THE REST OF THE CODE SHOULD WORK ONCE WE FIGURE THIS OUT
	// 
	// Fixed by closing used files
	AbstractFile* filePointer = abstractFileSystemPointer_->openFile(fileName);

	//If not formatted, remove all \n characters so it prints just raw data
	if (!formatted) {
		vector<char> fileData = filePointer->read();
		//remove(fileData.begin(), fileData.end(), '\n');
		//Print out file data
		for (int i = 0; i < fileData.size(); i++) {
			cout << fileData[i];
		}
	}
	//if formatted display, use basic display visitor
	else {
		AbstractFileVisitor* basicDisplayVisitor = new BasicDisplayVisitor();
		filePointer->accept(basicDisplayVisitor);

	}
	cout << endl;

	abstractFileSystemPointer_->closeFile(filePointer);
	return success;
}

void DisplayCommand::displayInfo() {
	cout << "Ds displays the file information. Using ds 'filename.txt' prints formatted data stored in 'filename.txt'. Adding '-d' afterwards will print unformatted data." << endl;
}