# Studio 19

1. Jack McCall and Nick Song

2. We changed the first character to be a ' ' instead of an X. We ran into an issue where we did not keept the size of the image
file in our new vector, so we had to manually add it back.

3. The visitor goes to the object, the object does all of the grunt work and gives whatever value is needed to the visitor, and then the visitor returns.

4. Delegation is important in OOP because it allows the code to be specific to whatever it's purpose is.

5. This would mean that every time we added a new file type, we would need to adjust the visitor file to allow for more functionality. This would be a bad idea when we have a lot of differnet file types, as we would need to add a lot of new functionality to the visitor class.

6.
Running main() from C:\Users\jacks\OneDrive\Documents\CompSci\cse332\studio16\out\build\x64-Debug\_deps\googletest-src\googletest\src\gtest_main.cc
[==========] Running 28 tests from 6 test suites.
[----------] Global test environment set-up.
[----------] 5 tests from textFile
[ RUN      ] textFile.constructor
[       OK ] textFile.constructor (0 ms)
[ RUN      ] textFile.write
[       OK ] textFile.write (0 ms)
[ RUN      ] textFile.append
[       OK ] textFile.append (0 ms)
[ RUN      ] textFile.read
[       OK ] textFile.read (0 ms)
[ RUN      ] textFile.readWithAppend
[       OK ] textFile.readWithAppend (0 ms)
[----------] 5 tests from textFile (1 ms total)

[----------] 6 tests from imageFile
[ RUN      ] imageFile.constructor
[       OK ] imageFile.constructor (0 ms)
[ RUN      ] imageFile.writeValid
[       OK ] imageFile.writeValid (0 ms)
[ RUN      ] imageFile.writeSizeMismatch
[       OK ] imageFile.writeSizeMismatch (0 ms)
[ RUN      ] imageFile.writeInvalidPixel
[       OK ] imageFile.writeInvalidPixel (0 ms)
[ RUN      ] imageFile.appendInvalid
[       OK ] imageFile.appendInvalid (0 ms)
[ RUN      ] imageFile.read
[       OK ] imageFile.read (0 ms)
[----------] 6 tests from imageFile (2 ms total)

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
[----------] 11 tests from simpleFileSystem (30 ms total)

[----------] 2 tests from simpleFileFactory
[ RUN      ] simpleFileFactory.createFileValid
[       OK ] simpleFileFactory.createFileValid (0 ms)
[ RUN      ] simpleFileFactory.createUnknownExtension
[       OK ] simpleFileFactory.createUnknownExtension (0 ms)
[----------] 2 tests from simpleFileFactory (9 ms total)

[----------] 2 tests from basicDisplayVisitor
[ RUN      ] basicDisplayVisitor.visitTextFile
[       OK ] basicDisplayVisitor.visitTextFile (0 ms)
[ RUN      ] basicDisplayVisitor.visitImageFile
[       OK ] basicDisplayVisitor.visitImageFile (0 ms)
[----------] 2 tests from basicDisplayVisitor (2 ms total)

[----------] 2 tests from metadataDisplayVisitor
[ RUN      ] metadataDisplayVisitor.visitTextFile
[       OK ] metadataDisplayVisitor.visitTextFile (0 ms)
[ RUN      ] metadataDisplayVisitor.visitImageFile
[       OK ] metadataDisplayVisitor.visitImageFile (0 ms)
[----------] 2 tests from metadataDisplayVisitor (2 ms total)

[----------] Global test environment tear-down
[==========] 28 tests from 6 test suites ran. (133 ms total)
[  PASSED  ] 28 tests.