#pragma once

#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

class TextFile : public AbstractFile {
private:
	vector<char> contents_;
	string name_;
public:
	TextFile(string name) : name_(name) {};
	vector<char>  read();
	virtual int write(vector<char> vc);
	int append(vector<char> vc);
	unsigned int getSize();
	string getName();
	void accept(AbstractFileVisitor* afv);
	AbstractFile* clone(string name);
};