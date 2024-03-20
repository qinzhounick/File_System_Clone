# Studio 17
1) Jack McCall and Nick Song

2)Test Cases:
[==========] Running 25 tests from 3 test suites.
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
[----------] 5 tests from textfile (7 ms total)

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

[----------] 14 tests from simpleFileSystem
[ RUN      ] simpleFileSystem.createFileValid
.img
.txt
[       OK ] simpleFileSystem.createFileValid (0 ms)
[ RUN      ] simpleFileSystem.createFileAlreadyExists
.img
[       OK ] simpleFileSystem.createFileAlreadyExists (0 ms)
[ RUN      ] simpleFileSystem.createUnknownExtension
.bla
[       OK ] simpleFileSystem.createUnknownExtension (0 ms)
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
.txt
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
[----------] 14 tests from simpleFileSystem (5 ms total)

[----------] Global test environment tear-down
[==========] 25 tests from 3 test suites ran. (18 ms total)
[  PASSED  ] 25 tests.

3)
Programming an interface is more flexible than a concrete class because if we want to add something in the future, we don't
have to change every class that uses the change, we only have to adjust the ones that need it.

4)
We would have to add code to the abstractFile class to make a generic createFile function; Or add another extension option 
  to our current createFile function.

5)
Test Cases:
[==========] Running 25 tests from 3 test suites.
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
[----------] 5 tests from textfile (7 ms total)

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

[----------] 14 tests from simpleFileSystem
[ RUN      ] simpleFileSystem.createFileValid
.img
.txt
[       OK ] simpleFileSystem.createFileValid (0 ms)
[ RUN      ] simpleFileSystem.createFileAlreadyExists
.img
[       OK ] simpleFileSystem.createFileAlreadyExists (0 ms)
[ RUN      ] simpleFileSystem.createUnknownExtension
.bla
[       OK ] simpleFileSystem.createUnknownExtension (0 ms)
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
.txt
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
[----------] 14 tests from simpleFileSystem (5 ms total)

[----------] Global test environment tear-down
[==========] 25 tests from 3 test suites ran. (18 ms total)
[  PASSED  ] 25 tests.