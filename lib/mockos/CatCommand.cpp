#include "mockos/CatCommand.h"
#include "mockos/BasicDisplayVisitor.h"

CatCommand::CatCommand(AbstractFileSystem* afsp) :
	abstractFileSystemPointer_(afsp) {}


int CatCommand::execute(std::string name) {
	istringstream iss(name);
	string fileName;
	iss >> fileName;

	//Check to make sure that file exists
	AbstractFile* filePointer = abstractFileSystemPointer_->openFile(fileName);
	if (filePointer == nullptr) {
		return fileNotFound;
	}
	
	//Check to see if there is another parameter
	string parameter;
	bool append = false;
	if (iss >> parameter) {
		//If parameter is -a, append to end of file instead of replacing
		if (parameter == "-a") {
			append = true;
		}
		else {
			return incorrectArgument;
		}
	}

	AbstractFileVisitor* basicDisplayVisitor = new BasicDisplayVisitor();
	filePointer->accept(basicDisplayVisitor);
	cout << endl;

	//User input prompt
	cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving." << endl;
	vector<char> newData;
	vector<string> userInputStrings;
	string userInput;
	getline(cin, userInput);
	bool loop = true;
	int errorCheck = 0;
	while (loop) {
		//If we need to save and quit
		if (userInput == ":wq") {
			//Pushing strings into the character vector
			for (int i = 0; i < userInputStrings.size(); i++) {
				string currentString = userInputStrings[i];
				//Iterate through each character in current string
				for (int j = 0; j < currentString.length(); j++) {
					newData.push_back(currentString[j]);
				}
				//Add in newline character if there is another line of input
				if (i < (userInputStrings.size() - indexing1)) {
					newData.push_back('\n');
				}
			}

			if (append) {
				errorCheck = filePointer->append(newData);
				if (errorCheck) {
					abstractFileSystemPointer_->closeFile(filePointer);
					return errorCatAppend;
				}
				else {
					abstractFileSystemPointer_->closeFile(filePointer);
					return success;
				}
			}
			else {
				errorCheck = filePointer->write(newData);
				if (errorCheck) {
					abstractFileSystemPointer_->closeFile(filePointer);
					return errorCatWrite;
				}
				else {
					abstractFileSystemPointer_->closeFile(filePointer);
					return success;
				}
			}
			loop = false;
		} 

		//If we need to quit without saving
		else if (userInput == ":q") {
			loop = false;
			abstractFileSystemPointer_->closeFile(filePointer);
			return success;

		}

		//If we need to prompt for more input
		else {
			userInputStrings.push_back(userInput);
			getline(cin, userInput);
		}
	}

	abstractFileSystemPointer_->closeFile(filePointer);
	return success;
}

void CatCommand::displayInfo() {
	cout << "Cat changes the info stored within a file. Using cat 'filename.txt' prompts for text to replace the data stored in 'filename.txt'. Adding '-a' afterwards will append the text to the file instead of replacing it." << endl;
}