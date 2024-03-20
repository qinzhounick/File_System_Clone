#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iterator>
#include <sstream>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;

class AbstractFileVisitor;

class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char> vc) = 0;
	virtual int append(vector<char> vc) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual ~AbstractFile() = default;
	virtual void accept(AbstractFileVisitor* afv) = 0;
	virtual AbstractFile* clone(string name) = 0;
};

enum errorCode {
	success = 0, fileAlreadyExists = 1, passedNullPointer = 2, unknownFileType = 3, fileNotOpen = 4,
	fileCurrentlyOpen = 5, fileNotFound = 6, invalidCharacter = 7, appendNotSupported = 8,
	passwordWriteFail = 9, passwordAppendFail = 10, userQuit = 11, executedCommandFailed = 12,
	errorAddingFile = 13, errorCreatingFile = 14, errorAddingCommand = 15, lsCommandFail = 16,
	incorrectArgument = 17, errorCatAppend = 18, errorCatWrite = 19, errorCopyCreate = 20, 
	errorCopyAdd = 21
};

enum indexing{ indexing1 = 1, indexing2 = 2, indexing48=48};