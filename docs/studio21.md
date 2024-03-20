# Studio 21

1. Jack McCall and Nick Song

2. When we destruct an object, and that object inherits from this class, we also need to destruct this class.

3. If we dont use injection, we would have to create an entirely new system every time. With the current setup, we can reuse the skeleton for our filesystem for a plethora of different file systems. It would be hard to use these instead because we would have to consider lots of different scenarios when creating the files and how users would interact with our system, rather than just making the file system fit for all users.

4. We ran all of the commands listed, and then opened the file it created successfully.

5. 
Running main() from C:\Users\jacks\OneDrive\Documents\CompSci\cse332\studio16\out\build\x64-Debug\_deps\googletest-src\googletest\src\gtest_main.cc
[==========] Running 42 tests from 10 test suites.
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
[----------] 6 tests from imageFile (1 ms total)

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
[----------] 11 tests from simpleFileSystem (11 ms total)

[----------] 2 tests from simpleFileFactory
[ RUN      ] simpleFileFactory.createFileValid
[       OK ] simpleFileFactory.createFileValid (0 ms)
[ RUN      ] simpleFileFactory.createUnknownExtension
[       OK ] simpleFileFactory.createUnknownExtension (0 ms)
[----------] 2 tests from simpleFileFactory (0 ms total)

[----------] 2 tests from basicDisplayVisitor
[ RUN      ] basicDisplayVisitor.visitTextFile
[       OK ] basicDisplayVisitor.visitTextFile (0 ms)
[ RUN      ] basicDisplayVisitor.visitImageFile
[       OK ] basicDisplayVisitor.visitImageFile (0 ms)
[----------] 2 tests from basicDisplayVisitor (0 ms total)

[----------] 2 tests from metadataDisplayVisitor
[ RUN      ] metadataDisplayVisitor.visitTextFile
[       OK ] metadataDisplayVisitor.visitTextFile (0 ms)
[ RUN      ] metadataDisplayVisitor.visitImageFile
[       OK ] metadataDisplayVisitor.visitImageFile (0 ms)
[----------] 2 tests from metadataDisplayVisitor (0 ms total)

[----------] 9 tests from passwordProxy
[ RUN      ] passwordProxy.constructor
[       OK ] passwordProxy.constructor (0 ms)
[ RUN      ] passwordProxy.writeValidPassword
[       OK ] passwordProxy.writeValidPassword (0 ms)
[ RUN      ] passwordProxy.writeInvalidPassword
[       OK ] passwordProxy.writeInvalidPassword (0 ms)
[ RUN      ] passwordProxy.appendValidPassword
[       OK ] passwordProxy.appendValidPassword (0 ms)
[ RUN      ] passwordProxy.appendInvalidPassword
[       OK ] passwordProxy.appendInvalidPassword (0 ms)
[ RUN      ] passwordProxy.readValidPassword
[       OK ] passwordProxy.readValidPassword (0 ms)
[ RUN      ] passwordProxy.readInvalidPassword
[       OK ] passwordProxy.readInvalidPassword (0 ms)
[ RUN      ] passwordProxy.acceptValidPassword
[       OK ] passwordProxy.acceptValidPassword (0 ms)
[ RUN      ] passwordProxy.acceptInvalidPassword
[       OK ] passwordProxy.acceptInvalidPassword (0 ms)
[----------] 9 tests from passwordProxy (4 ms total)

[----------] 2 tests from commandPrompt
[ RUN      ] commandPrompt.runQuit
[       OK ] commandPrompt.runQuit (0 ms)
[ RUN      ] commandPrompt.runHelp
[       OK ] commandPrompt.runHelp (0 ms)
[----------] 2 tests from commandPrompt (2 ms total)

[----------] 2 tests from commandTest
[ RUN      ] commandTest.commandDisplayInfo
[       OK ] commandTest.commandDisplayInfo (0 ms)
[ RUN      ] commandTest.commandExecuteNoInfo
[       OK ] commandTest.commandExecuteNoInfo (0 ms)
[----------] 2 tests from commandTest (1 ms total)

[----------] 1 test from touchCommand
[ RUN      ] touchCommand.execute
[       OK ] touchCommand.execute (0 ms)
[----------] 1 test from touchCommand (0 ms total)

[----------] Global test environment tear-down
[==========] 42 tests from 10 test suites ran. (74 ms total)
[  PASSED  ] 42 tests.