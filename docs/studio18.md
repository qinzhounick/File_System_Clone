# Studio 18

1. Jack McCall and Nick Song

2. Our current factory method is efficient enough, since the current file types that we have only require a name
as a parameter in their constructors. Assuming that any new file types also only require a name, we can keep generally
the same format that we already have in the future, and it should work out alright. We would only need to adjust
the create file and add file, since those are the only two functions that we currently have that check for extensions.

3. We would want to make one total per program. If we have a new file type, all we would need to modify is the createFile
function. Specifically, adding the new import, adding a new check for the new file extension, and a new return possibility.
The same factory can create files for both since it does not interact directly with the SimpleFileSystem, it merely
returns the file. It can be used for both if they use different file types, so long as all file types are options within 
the SimpleFileFactory.

4. Test run:
    vector<char> vc1{ 'X', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', '3' };
    afs->openFile(if1->getName());
    if1->write(vc1);
    if1->read();
    afs->closeFile(if1);
    cout << "test close file" << endl;

    Output is as expected, returned with code 0 and got to cout statement without crashing.

5. We only have a dependency on the AbstractFile interface now.

6. Passes all test cases.
[==========] Running 24 tests from 4 test suites.
[----------] Global test environment set-up.
[----------] 5 tests from textfile
[ RUN      ] textfile.constructor
[       OK ] textfile.constructor (0 ms)
[ RUN      ] textfile.write
[       OK ] textfile.write (0 ms)
[ RUN      ] textfile.append
[       OK ] textfile.append (0 ms)
[ RUN      ] textfile.read
[       OK ] textfile.read (0 ms)
[ RUN      ] textfile.readwithAppend
[       OK ] textfile.readwithAppend (0 ms)
[----------] 5 tests from textfile (1 ms total)

[----------] 6 tests from imagefile
[ RUN      ] imagefile.constructor
[       OK ] imagefile.constructor (0 ms)
[ RUN      ] imagefile.writeValid
[       OK ] imagefile.writeValid (0 ms)
[ RUN      ] imagefile.writeSizeMismatch
ERROR
[       OK ] imagefile.writeSizeMismatch (0 ms)
[ RUN      ] imagefile.writeInvalidPixel
ERROR
[       OK ] imagefile.writeInvalidPixel (0 ms)
[ RUN      ] imagefile.appendInvalid
[       OK ] imagefile.appendInvalid (0 ms)
[ RUN      ] imagefile.read
[       OK ] imagefile.read (0 ms)
[----------] 6 tests from imagefile (2 ms total)

[----------] 11 tests from simpleFileSystem
[ RUN      ] simpleFileSystem.addValid
[       OK ] simpleFileSystem.addValid (0 ms)
[ RUN      ] simpleFileSystem.addNullFile
[       OK ] simpleFileSystem.addNullFile (0 ms)
[ RUN      ] simpleFileSystem.addFileAlreadyExists
[       OK ] simpleFileSystem.addFileAlreadyExists (0 ms)
[ RUN      ] simpleFileSystem.deleteValid
[       OK ] simpleFileSystem.deleteValid (0 ms)
[ RUN      ] simpleFileSystem.deleteFileDoesNotExist
[       OK ] simpleFileSystem.deleteFileDoesNotExist (0 ms)
[ RUN      ] simpleFileSystem.openValid
[       OK ] simpleFileSystem.openValid (0 ms)
[ RUN      ] simpleFileSystem.openFileNotAdded
[       OK ] simpleFileSystem.openFileNotAdded (0 ms)
[ RUN      ] simpleFileSystem.openAlreadyOpenedFile
[       OK ] simpleFileSystem.openAlreadyOpenedFile (0 ms)
[ RUN      ] simpleFileSystem.closeValid
[       OK ] simpleFileSystem.closeValid (0 ms)
[ RUN      ] simpleFileSystem.closeNotOpen
[       OK ] simpleFileSystem.closeNotOpen (0 ms)
[ RUN      ] simpleFileSystem.closeNotAdded
[       OK ] simpleFileSystem.closeNotAdded (0 ms)
[----------] 11 tests from simpleFileSystem (152 ms total)

[----------] 2 tests from simpleFileFactory
[ RUN      ] simpleFileFactory.createFileValid
[       OK ] simpleFileFactory.createFileValid (0 ms)
[ RUN      ] simpleFileFactory.createUnknownExtension
[       OK ] simpleFileFactory.createUnknownExtension (0 ms)
[----------] 2 tests from simpleFileFactory (1 ms total)

[----------] Global test environment tear-down
[==========] 24 tests from 4 test suites ran. (160 ms total)
[  PASSED  ] 24 tests.