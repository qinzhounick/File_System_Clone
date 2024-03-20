#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"

void BasicDisplayVisitor::visit_image(ImageFile* ifile) {

	//Starting from the top left, print out each row of the image file
	vector<char> file_contents = ifile->read();
	int sizeInt = (int)sqrt(ifile->getSize());

	for (int y = sizeInt - 1; y >= 0; y--) {
		for (int x = 0; x < sizeInt; x++) {
			int index = y * sizeInt + x;
			cout << file_contents[index];
		}
		cout << endl;
	}

}

void BasicDisplayVisitor::visit_text(TextFile* tfile) {
	vector<char> file_contents = tfile->read();
	for (int i = 0; i < file_contents.size(); i++) {
		cout << file_contents[i];
	}
}