#pragma once

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor:public AbstractFileVisitor {
public:
	void visit_image(ImageFile* ifile);
	void visit_text(TextFile* tfile);
};