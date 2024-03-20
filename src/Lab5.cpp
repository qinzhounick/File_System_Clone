#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/MetadataDisplayVisitor.h"
#include "mockos/PasswordProxy.h"
#include "mockos/TouchCommand.h"
#include "mockos/CommandPrompt.h"
#include "mockos/LSCommand.h"
#include "mockos/RemoveCommand.h"
#include "mockos/CatCommand.h"
#include "mockos/DisplayCommand.h"
#include "mockos/CopyCommand.h"
#include "mockos/MacroCommand.h"
#include "mockos/RenameParsingStrategy.h"
#include "mockos/DisplayEditsParsingStrategy.h"

using namespace std;


int main() {
    AbstractFileSystem* afs = new SimpleFileSystem();
    AbstractFileFactory* aff = new SimpleFileFactory();

    //Initializing Command Prompt
    CommandPrompt* cmd = new CommandPrompt();
    cmd->setFileFactory(aff);
    cmd->setFileSystem(afs);

    //Commands
    AbstractCommand* ls = new LSCommand(afs);
    AbstractCommand* touchy = new TouchCommand(afs, aff);
    AbstractCommand* removeFile = new RemoveCommand(afs);
    AbstractCommand* catFile = new CatCommand(afs);
    AbstractCommand* displayFile = new DisplayCommand(afs);
    AbstractCommand* copyFile = new CopyCommand(afs);
    MacroCommand* macro1 = new MacroCommand(afs);
    AbstractParsingStrategy* rename = new RenameParsingStrategy();
    MacroCommand* macro2 = new MacroCommand(afs);
    AbstractParsingStrategy* displayedits = new DisplayEditsParsingStrategy();

    macro1->setParseStrategy(rename);
    macro1->addCommand(copyFile);
    macro1->addCommand(removeFile);

    macro2->setParseStrategy(displayedits);
    macro2->addCommand(catFile);
    macro2->addCommand(displayFile);

    cmd->addCommand("touch", touchy);
    cmd->addCommand("ls", ls);
    cmd->addCommand("rm", removeFile);
    cmd->addCommand("cat", catFile);
    cmd->addCommand("ds", displayFile);
    cmd->addCommand("cp", copyFile);
    cmd->addCommand("rn", macro1);
    cmd->addCommand("catds", macro2);
    cmd->run();

    return 0;
}