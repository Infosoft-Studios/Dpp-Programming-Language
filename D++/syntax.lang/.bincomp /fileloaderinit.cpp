void * buffer();
reinterper_cast<void*> buffer();

#include <windows.h>

void __main__()
{
    WINCLASS wc;
    wc.loadinit              = SystemReloadEx(nullptr, true, false);
};
