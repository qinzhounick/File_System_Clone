#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;


int main() {
    AbstractFileSystem* afs = new SimpleFileSystem();
    AbstractFileFactory* aff = new SimpleFileFactory();
    AbstractFileVisitor* afv = new BasicDisplayVisitor();

    AbstractFile* if1 = aff->createFile("test.img");

    afs->addFile(if1->getName(), if1);

    vector<char> vc1{'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', '3'};
    afs->openFile(if1->getName());
    if1->write(vc1);
    
    if1->accept(afv);

    

    return 0;
}

