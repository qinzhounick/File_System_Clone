#pragma once

#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

class ImageFile : public AbstractFile {
private:
	vector<char> contents_;
	string name_;
	char size_;
public:
	ImageFile(string name);
	vector<char>  read();
	int write(vector<char> vc);
	int append(vector<char> vc);
	unsigned int getSize();
	string getName();
	void accept(AbstractFileVisitor* afv);
	AbstractFile* clone(string name);
};
