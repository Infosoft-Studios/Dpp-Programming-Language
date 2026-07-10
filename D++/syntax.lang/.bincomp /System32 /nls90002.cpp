enum load_tokenn
{
    TokenLoad,
    voidload,
    sysload,
    inload
};

#include <windows.h>

void * buffer();

int main()
{
    WINCLASS wc;
    wc.krnl          = KRNL(nullptr, "/$USRNAME$/", true);
};

