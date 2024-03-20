#include "AbstractFileSystem.h"
#include <map>
#include <set>

#pragma once

class SimpleFileSystem : public AbstractFileSystem {
private:
	map<string, AbstractFile*> stringToPointerMap_;
	set<AbstractFile*> openFiles_;
public:
	virtual int addFile(string filename, AbstractFile* af);
	virtual int deleteFile(string filename);
	virtual AbstractFile* openFile(string filename);
	virtual int closeFile(AbstractFile* af);
	virtual set<string> getFileNames();

	//prints contents of map and set
	void print();
}
;