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

using namespace std;


int main() {
    AbstractFileSystem* afs = new SimpleFileSystem();
    AbstractFileFactory* aff = new SimpleFileFactory();
    AbstractCommand* touchy = new TouchCommand(afs, aff);
    CommandPrompt* cmd = new CommandPrompt(afs, aff);
    
    cmd->addCommand("touch", touchy);
    cmd->run();

    return 0;
}