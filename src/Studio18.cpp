#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"

using namespace std;


int main() {
    AbstractFileSystem* afs = new SimpleFileSystem();
    AbstractFileFactory* aff = new SimpleFileFactory();
    
    AbstractFile* tf1 = aff->createFile("test.txt");
    AbstractFile* tf2 = aff->createFile("hello.txt");
    AbstractFile* if1 = aff->createFile("image.img");
    AbstractFile* if2 = aff->createFile("funnypicture.img");

    afs->addFile(tf1->getName(), tf1);
    afs->addFile(tf2->getName(), tf2);
    afs->addFile(if1->getName(), if1);
    afs->addFile(if2->getName(), if2);

    vector<char> vc1{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', '3' };
    afs->openFile(if1->getName());
    if1->write(vc1);
    if1->read();
    afs->closeFile(if1);
    cout << "test close file" << endl;


    return 0;
}

