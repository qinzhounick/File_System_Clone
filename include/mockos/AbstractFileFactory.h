#include "AbstractFile.h"

#pragma once

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string filename) = 0;
}
;