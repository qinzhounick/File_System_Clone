#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/SimpleFileSystem.h"

using namespace std;


int main() {
    /*
    ImageFile testImageFile = ImageFile("boing");
    //cout << tf.getName();
    vector<char> vc1{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', '3'};
    //vector<char> vc2{ 'N', 'A', ' ', ' ', ' ', 'X', 'X', 'X', ' ', '3' };
    //vector<char> vc2 = { 'N', 'O' };
    //testImageFile.write(vc2);
    //tf.getSize();
    //tf.append(vc2);
    //tf.getSize();
    testImageFile.read();

    //AbstractFile& af = tf;
    //af.write(vc1);
    //af.read();
    */
    
    SimpleFileSystem* mySFS = new SimpleFileSystem();
    ImageFile* testImageFile1 = new ImageFile("bongo.img");
    ImageFile* testImageFile2 = new ImageFile("bingo");
    TextFile* testTextFile1 = new TextFile("Hello.txt");
    TextFile* testTextFile2 = new TextFile("Goobye");



    mySFS->addFile(testImageFile1->getName(), testImageFile1);
    cout << "added testImageFile1" << endl;
    mySFS->print();

    mySFS->createFile("newbornFile.img");
    cout << "created newbornFile.img" << endl;
    cout << "test create file" << endl;
    mySFS->print();

    mySFS->createFile("broken");
    cout << "test create broken file" << endl;
    mySFS->print();
    
    mySFS->openFile("bongo.img");
    cout << "test open file" << endl;
    mySFS->print();

    vector<char> vc1{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', '3' };
    testImageFile1->write(vc1);
    testImageFile1->read();

    mySFS->closeFile(testImageFile1);
    cout << "test close file" << endl;
    mySFS->print();
    mySFS->deleteFile("bongo.img");
    cout << "test delete file" << endl;
    mySFS->print();
    return 0;
}

