#include "../include/mockos/MetadataDisplayVisitor.h"
#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"

void MetadataDisplayVisitor::visit_image(ImageFile* ifile) {
	cout << left << setw(20) << ifile->getName() << left << setw(10) << "image" << left << setw(6) << ifile->getSize() <<  endl;
}
void MetadataDisplayVisitor::visit_text(TextFile* tfile) {
	cout << left << setw(20) << tfile->getName() << left << setw(10) << "text" << left << setw(6) << tfile->getSize() << endl;
}