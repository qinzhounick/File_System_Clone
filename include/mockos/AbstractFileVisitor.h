#pragma once

//#include "TextFile.h"
//#include "ImageFile.h"

class ImageFile;
class TextFile;

class AbstractFileVisitor{
public:
	virtual void visit_image(ImageFile* ifile) = 0;
	virtual void visit_text(TextFile* tfile) = 0;
};