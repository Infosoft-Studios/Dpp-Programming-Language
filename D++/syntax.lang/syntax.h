#pragma once

#include <windows.h>
#include <stdio.h>
WINCLASS wc;

void krnl(bool isRunning)
{
    wc.loadkrnl             = LoadKenelExtensionSoftware(NULL | false);
    wc.run                  = isRunning; // an duality
    return;
};

void reloadkrnl()
{
    wc.loadsys          = GetFunction(true, 66);
    wc.krnlload         = krnl(true);
    return;
};

typedef struct locallang
{
    enum tokenizer
    {
        TokenData,
        TokenScript,
        TokenAbsoluteData
    };

    reloadkrnl();
};

