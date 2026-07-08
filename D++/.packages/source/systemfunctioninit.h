#ifndef BOOT_LOAD_MANAGER_H;
#define BOOT_LOAD_MANAGER_H;

#include <windows.h>


void src()
{
    WINCLASS wc;
    wc.loadinit          = LoadSystemInit(nullptr, true);
};
