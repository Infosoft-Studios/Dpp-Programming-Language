#pragma once 

#include <windows.h>
#include <string>

void loadbinaryconferences(string SysDirDirPath)
{
    WINCLASS wc;
    wc.sysdir              = LoadSysdir(true , SysDirDirPath);
    wc.loadinitiailyzer    = FunctionSys(true, nullptr);
    swicth (!wc.loadfunctions)
    {
        case wc.loader || wc.functioninitializer:
            break;
        default:
            break;
    };
};

int main()
{
    loadbinaryconferences("C:\\Windows\\System32\\");
};

