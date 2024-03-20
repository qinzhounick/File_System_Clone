#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/ImageFile.h"

AbstractFile* SimpleFileFactory::createFile(string filename) {
	//If file name is not long enough to properly hold file extension, return nullptr
	if (filename.length() < 5) {
		return nullptr;
	}

	string extension = filename.substr(filename.length() - 4, filename.length() - 1);
	string txtExtension = ".txt";
	string imgExtension = ".img";

	//If creating text file
	if (extension == txtExtension) {
		TextFile* textf = new TextFile(filename);
		return textf;
	}
	//If creating image file
	else if (extension == imgExtension) {
		ImageFile* imagef = new ImageFile(filename);
		return imagef;
	}
	//If unknown file type
	return nullptr;

}