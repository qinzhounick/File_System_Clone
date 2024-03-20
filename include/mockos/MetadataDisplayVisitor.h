#pragma once

#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor: public AbstractFileVisitor {
public:
	void visit_image(ImageFile* ifile);
	void visit_text(TextFile* tfile);
};