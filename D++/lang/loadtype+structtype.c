#include <stdio.h>
#include <windows.h>
// Include precompiled.hpp
#include "precompiled.hpp"

typedef struct exe
{
    enum tokentype
    {
        CPUTOKEN,
        LANGTOKEN,
        EXEEDTOKEN
    }

    WINDCLASS wc;
    wc.load                 = WINTYPE::WinClassWC; // load from enum
}

void loadstruct_exe()
{
    return;
};
