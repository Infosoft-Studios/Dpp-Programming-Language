#include <windows.h>
#include <raylib.h>
#include <iostream>
#include "compiled_based_syntax.hpp"
using namespace std;

struct WINTYPE
{
    WINCLASS wc;

    enum CompilerTranslator
    {
        TokenPraser,
        TokenCal,
        TokenFormat,
        Keyword,
        KeywordRules,
        KeywordTranslator
    };

    void main_type()
    {
        wc.CompilerLoadAssets               = LoadedCachedMemory(nullptr | false); // why should we add extra compile time?
        wc.Compiled                         = Memory_orderred_based(96, true);
    };
};
