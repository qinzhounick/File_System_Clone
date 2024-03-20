#include "mockos/TouchCommand.h"

TouchCommand::TouchCommand(AbstractFileSystem* afsp, AbstractFileFactory* aff): 
	abstractFileSystemPointer_(afsp), abstractFileFactoryPointer_(aff) {}


int TouchCommand::execute(std::string name) {
	istringstream iss(name);
	string fileName;
	iss >> fileName;
	//Check to see if there is another parameter
	string parameter;
	if (iss >> parameter) {

		//If parameter is -p, create password protected file instead
		if (parameter == "-p") {
			cout << "Please enter a password to protect this file: ";
			string password;
			getline(cin, password);

			//Making sure password has no spaces in it
			if (password.find(" ") == std::string::npos) {
				AbstractFile* newFile = abstractFileFactoryPointer_->createFile(fileName);

				//If created successfully, check if password proxy created successfully
				if (newFile != nullptr) {
					AbstractFile* passwordProtectedFile = new PasswordProxy(newFile, password);
					if (passwordProtectedFile != nullptr) {

						int errorCheck = abstractFileSystemPointer_->addFile(fileName, passwordProtectedFile);
						if (errorCheck != 0) {
							//Delete file and return error
							abstractFileSystemPointer_->deleteFile(fileName);
							return errorAddingFile;
						}
					}
					//Can't create Password Proxy
					else {
						return errorCreatingFile;
					}
				}
				//Can't create regular file
				else {
					return errorCreatingFile;
				}
			}
		}
		//If second argument is not '-p'
		else {
			return incorrectArgument;
		}
	} 
	//If we don't have a second parameter, create like usual
	else {
		AbstractFile* newFile = abstractFileFactoryPointer_->createFile(fileName);
		//If created successfully
		if (newFile != nullptr) {
			int errorCheck = abstractFileSystemPointer_->addFile(fileName, newFile);
			if (errorCheck != 0) {
				//Delete file and return error
				abstractFileSystemPointer_->deleteFile(fileName);
				return errorAddingFile;
			}
		}
		else {
			return errorCreatingFile;
		}
	}
	return success;
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch<filename>. Include '-p' afterwards to create a password protected file." << endl;
}