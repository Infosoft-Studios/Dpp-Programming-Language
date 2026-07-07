#include <windows.h>

void load()
{
    WINCLASS wc;
    wc.loadenit       = LoadSystemCallPoint_krnl("%krnl%", nullptr);
};

#include <iostream>

int main()
{
    WINCLASS wc;
    cout << load() << std::endl;
}
