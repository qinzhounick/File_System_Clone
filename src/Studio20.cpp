#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/MetadataDisplayVisitor.h"
#include "mockos/PasswordProxy.h"

using namespace std;


int main() {
    AbstractFileFactory* aff = new SimpleFileFactory();
    AbstractFile* if1 = aff->createFile("test.img");
    PasswordProxy* pp = new PasswordProxy(if1, "1234");
    AbstractFileVisitor* afv = new BasicDisplayVisitor();

    vector<char> vc1{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', '3' };
    pp->write(vc1);
    pp->read();
    pp->accept(afv);


    return 0;
}