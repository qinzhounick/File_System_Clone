#include "AbstractFileFactory.h"

#pragma once

class SimpleFileFactory:public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string filename);
};