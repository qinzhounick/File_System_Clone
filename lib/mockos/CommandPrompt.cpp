#include "mockos/CommandPrompt.h"

using namespace std;


CommandPrompt::CommandPrompt() :
	abstractFileSystemPointer_(nullptr), abstractFileFactoryPointer_(nullptr) {}


void CommandPrompt::setFileSystem(AbstractFileSystem* afs) {
	abstractFileSystemPointer_ = afs;
}


void CommandPrompt::setFileFactory(AbstractFileFactory* aff) {
	abstractFileFactoryPointer_ = aff;
}


int CommandPrompt::addCommand(std::string name, AbstractCommand* ac) {
	std::pair<std::map<string, AbstractCommand*>::iterator, bool> returnVal;
	returnVal = pointerToCommandMap_.insert({ name, ac });
	if (returnVal.second == false) {
		return errorAddingCommand;
	}
	return success;
}


int CommandPrompt::run() {
	while (1) {
		string userInput = prompt();
		//User wants to quit
		if (userInput == "q") {
			return userQuit;
		}
		//User wants help
		else if (userInput == "help") {
			CommandPrompt::listCommands();
		}
		//User has entered command
		else {
			//check to see if input is only one word
			if (userInput.find(" ") == std::string::npos) {
				//Search map for command
				map<std::string, AbstractCommand*>::iterator it = pointerToCommandMap_.find(userInput);
				if (it != pointerToCommandMap_.end()) {
					int errorCheck = it->second->execute("");
					//If error occured 
					if (errorCheck != 0) {
						cout << "Command " << it->first << " failed!" << endl;
					}
				}
				//If command doesn't exist
				else {
					cout << "Error! Command " << userInput << " doesn't exist!" << endl;
				}
			} 
			//If longer that one word
			else {
				istringstream iss(userInput);
				string firstWord;
				iss >> firstWord;
				//If first word is "help"
				if (firstWord == "help") {
					string secondWord;
					iss >> secondWord;
					map<std::string, AbstractCommand*>::iterator it = pointerToCommandMap_.find(secondWord);
					if (it != pointerToCommandMap_.end()) {
						it->second->displayInfo();
					}
					//If command doesn't exist
					else {
						cout << "Error! Command " << it->first << " doesn't exist!" << endl;
					}
				}
				//If first word is NOT help
				else {
					string secondWord;
					iss >> secondWord;
					
					//Checking to see if there is a second parameter
					//If so, concatenate with first word
					string thirdWord;
					if (iss >> thirdWord) {
						secondWord = secondWord + " " + thirdWord;
					}
					//Search map for command
					map<std::string, AbstractCommand*>::iterator it = pointerToCommandMap_.find(firstWord);
					if (it != pointerToCommandMap_.end()) {
						int errorCheck = it->second->execute(secondWord);
						//cout << "Error: " << errorCheck << endl;
						//If error occured 
						if (errorCheck != 0) {
							cout << "Command " << it->first << " failed!" << endl;
						}
					}
					//If command doesn't exist
					else {
						cout << "Error! Command doesn't exist!" << endl;
					}
				}
			}
		}
	}
}


void CommandPrompt::listCommands() {
	//Make iterator towards beginning of map
	map<std::string, AbstractCommand*>::iterator it = pointerToCommandMap_.begin();
	cout << "All available commands: " << endl;
	//Iterate through map and print out commands
	while (it != pointerToCommandMap_.end()) {
		cout << it->first << endl;
		it++;
	}
	cout << endl;

}


std::string CommandPrompt::prompt() {
	cout << endl;
	cout << "Please enter one of the options below: " << endl;
	cout << "- A valid command" << endl;
	cout << "- \"q\" to quit" << endl;
	cout << "- \"help\" for a list of commands" << endl;
	cout << "- Or \"help<command name>\" for detais about a specific command" << endl;
	cout << "$  ";
	string command;

	getline(cin, command);
	while (command.empty()) {
		getline(cin, command);
	}
	//cout << endl << command;
	return command;

}