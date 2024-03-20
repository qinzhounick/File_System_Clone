#include "../include/mockos/SimpleFileSystem.h"
#include <iostream>


int SimpleFileSystem::addFile(string filename, AbstractFile* af) {
	//Check map to see if file does not already exist
	if (stringToPointerMap_.count(filename)) {
		return fileAlreadyExists;
	}

	//Check to see if af pointer is nullpointer
	if (af == nullptr) {
		return passedNullPointer;
	}

	//Make pair and insert into map
	pair<string, AbstractFile*> keyValue = make_pair(filename, af);
	stringToPointerMap_.insert(keyValue);
	return success;
}


AbstractFile* SimpleFileSystem::openFile(string filename) {
	//If file does not exist in map, return nullptr
	if (!(stringToPointerMap_.count(filename))) {
		return nullptr;
	}



	//grab pointer from map, insert into openFiles_
	AbstractFile* filePointer = stringToPointerMap_.at(filename);

	//If in set of already open files, return nullptr
	if (openFiles_.count(filePointer)) {
		return nullptr;
	}

	openFiles_.insert(filePointer);
	return filePointer;
}

int SimpleFileSystem::closeFile(AbstractFile* af) {
	//If file in openFiles, delete and return
	if (openFiles_.count(af)) {
		openFiles_.erase(af);
		return success;
	}
	//If file NOT in openFiles
	return fileNotOpen;
}

int SimpleFileSystem::deleteFile(string filename) {
	//If file exists
	if (stringToPointerMap_.count(filename)) {
		//grab pointer from map
		AbstractFile* filePointer = stringToPointerMap_.at(filename);

		//If in set of already open files, return nullptr
		if (openFiles_.count(filePointer)) {
			return fileCurrentlyOpen;
		}

		//Remove from map, delete allocated pointer
		stringToPointerMap_.erase(filename);
		delete filePointer;
		return success;
	}
	//If file doesn't exist
	else {
		return fileNotFound;
	}
}


void SimpleFileSystem::print() {
	//Make map iterator
	map<string, AbstractFile*>::iterator mapit;

	set<AbstractFile*>::iterator setit;

	cout << "Map Info: " << endl;
	for (mapit = stringToPointerMap_.begin(); mapit != stringToPointerMap_.end(); mapit++)
	{
		cout << mapit->first << " , " << mapit->second << endl;
	}

	cout << "Set Info: " << endl;
	for (setit = openFiles_.begin(); setit != openFiles_.end(); setit++)
	{
		cout << *setit << endl;
	}
}

set<string> SimpleFileSystem::getFileNames() {
	//Make iterator towards beginning of map
	map<std::string, AbstractFile*>::iterator it = stringToPointerMap_.begin();
	set<string> fileSet;
	//Iterate through map and add file names to fileSet
	while (it != stringToPointerMap_.end()) {
		fileSet.insert(it->first);
		it++;
	}
	return fileSet;
}