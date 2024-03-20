# Lab 5
Nick Song
Jack Mccall

#WORK DISTRIBUTION
Jack did questions 1-5 and Nick worked on questions 6-10

#ERRORS
Our LS command was not working properly if we use it the second time on one file, because after we open file to display its info, we forgot to close it. We added a closeFile everytime after we used openFile and the bug was fixed.
Our lab5 failed to build after adding new ParsingStrategy file because the mockos CMakeList was not updated.
Our CatCommand was failing to write to img file because it put a '\n' character at the end of the input and the image "write" function took in that new line character as the size. We fixed it by adding new line character only if it's not the last line of input.
Our CatCommand did not pass the textFileAppendSaving and no Saving cases, because we did not print out the original contents. We solved it by using a basicFileVisitor and printed out the original contents. 
Our CatCommand had an infinite loop because our nested for loop was both incrementing i so j never got incremented. We fixed it by changing the i to j in the inner loop.

9. We chose to do a cat+ds MacroCommand. 
Usage: catds filename.txt
OR catds filename.txt -a
OR catds filename.txt -d
OR catds filename.txt -a -d

Test cases:

[1] catds filename.img
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  catds haha.img
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
X X X X X3
:wq
X X
 X
X X

[2] catds filename.img -d
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  catds haha.img -d
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
X X X X X3
:wq
X X X X X

[3] catds filename.img -a
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  catds haha.img -a
X X
 X
X X

Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
X X X X X3
:wq
Command catds failed!

[4] catds filename.txt
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  catds ll.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
1234
:wq
1234

[5] catds filename.txt -a
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  catds ll.txt -a
1234
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
4321
:wq
12344321

[6] catds filename.txt -a -d
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  catds ll.txt -a -d
12344321
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.

1111
:wq
12344321
1111


10. Test all commands
#LSCommand:
[1] ls
Output:
Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ls
a.img               b.txt
haha.txt

[2]ls -m
Output:
Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ls -m
a.img               image     9
b.txt               text      4
haha.txt            text      0

#RemoveCommand
[1]rm
Output:
Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  rm haha.txt

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ls
a.img               b.txt

#touchCommand with Password
[1] touch filename.txt -p
Output:
Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  touch haha.txt -p
Please enter a password to protect this file: 1234

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat haha.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
1111
:wq
Please enter password: 1234

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds haha.txt
Please enter password: 1234
1111

#catCommand
[1] cat filename :wq
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat ll.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
1234
:wq

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds ll.txt
1234

[2] cat filename :q
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat ll.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
4321:q
:q

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds ll.txt
1234

[3] cat filename -a :wq
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat ll.txt -a
1234
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
4321
:wq

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds ll.txt
12344321

[4] cat filename -a :q
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat ll.txt -a
12344321
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
1111
:q

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds ll.txt
12344321

#DisplayCommand
[1]ds filename
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat haha.img
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
X X X X X3
:wq

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds haha.img
X X
 X
X X

[2]ds filename -d
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds haha.img -d
X X X X X

#CopyCommand
[1] cp filename copyfilename
Output:

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  touch origin.txt

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat origin.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
12345
:wq

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cp origin.txt copy

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds copy.txt
12345

[2] cp filename copyfilename (with password)
Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  touch originwithpassword.txt -p
Please enter a password to protect this file: 1234

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat originwithpassword.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
hello
:wq
Please enter password: 1234

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cp originwithpassword.txt copywithpassword

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds copywithpassword.txt
Please enter password: 1234
hello

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat copywithpassword.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
hi
:wq
Please enter password: 1234

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds originwithpassword.txt
Please enter password: 1234
hello


#Rename MacroCommand
[1] rn filename newname
Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  touch out.txt

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  cat out.txt
Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving.
12345
:wq

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  rn out.txt in

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ls
in.txt

Please enter one of the options below:
- A valid command
- "q" to quit
- "help" for a list of commands
- Or "help<command name>" for detais about a specific command
$  ds in.txt
12345

