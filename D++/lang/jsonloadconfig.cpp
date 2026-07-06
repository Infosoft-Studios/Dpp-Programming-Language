#include <windows.h>
#include <raylib.h>
#include <iostream>
#include "configuration_loader_compiler.c"
using namespace std;

void load_functionalAssets()
{
    WINCLASS wc;
    wc.loadtoken                = CompiledTokenReaction::Argument;
    wc.getArgument              = wc.loadToken | CompiledTokenReaction::Argument; 

    return 0;
}
