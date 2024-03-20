#pragma once
#include "AbstractFile.h"

using namespace std;

class PasswordProxy: public AbstractFile{
private: 
	AbstractFile* protectedFile_;
	string password_;
public:
	PasswordProxy(AbstractFile* af, string password);
	~PasswordProxy();
	vector<char> read();
	int write(vector<char> vc);
	int append(vector<char> vc);
	unsigned int getSize();
	string getName();
	void accept(AbstractFileVisitor* afv);
	AbstractFile* clone(string name);
protected:
	string passwordPrompt();
};