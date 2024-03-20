#include "../include/mockos/TextFile.h"

unsigned int TextFile::getSize(){
	return TextFile::contents_.size();
}

string TextFile::getName() {
	return TextFile::name_;
}

int TextFile::write(vector<char> vc) {
	TextFile::contents_ = vc;

	return success;
}

int TextFile::append(vector<char> vc) {
	for (int i = 0; i < vc.size(); i++) {
		TextFile::contents_.push_back(vc[i]);
	}

	return success;
}

vector<char>  TextFile::read() {
	return contents_;
}


void TextFile::accept(AbstractFileVisitor* afv) {
	afv->visit_text(this);
}

AbstractFile* TextFile::clone(string name) {
	TextFile* tempFile = new TextFile(*this);
	tempFile->name_ = name + ".txt";
	AbstractFile* copyFile = tempFile;
	return copyFile;
}