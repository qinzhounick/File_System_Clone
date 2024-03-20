#include "../include/mockos/ImageFile.h"


ImageFile::ImageFile(string name) : name_(name), size_(0) {}


unsigned int ImageFile::getSize() {
	return ImageFile::contents_.size();
}

string ImageFile::getName() {
	return ImageFile::name_;
}

int ImageFile::write(vector<char> vc) {
	//If already data in contents_, clear before writing new data
	if (size_ != 0) {
		contents_.clear();
	}
	int charValueFor0 = indexing48; //ASCII value for 0 for converting char to int
	size_ = vc[vc.size() - indexing1];
	int sizeInt = size_ - '0';
	for (int i = 0; i < (sizeInt * sizeInt); i++) {
		char currentChar = vc[i];
		//If invalid character, delete contents and set size to 0
		//Returns error message showing invalid character
		if (currentChar != 'X' && currentChar != ' ') {
			cout << "ERROR" << endl;
			contents_.clear();
			size_ = '0';
			return invalidCharacter;
		}
		contents_.push_back(currentChar);
	}
	return success;
}

int ImageFile::append(vector<char> vc) {
	return appendNotSupported;
}

//Prints out image file in a grid
vector<char>  ImageFile::read() {
	return contents_;
}

void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_image(this);
}

AbstractFile* ImageFile::clone(string name) {
	ImageFile* tempFile = new ImageFile(*this);
	tempFile->name_ = name + ".img";
	AbstractFile* copyFile = tempFile;
	return copyFile;
}