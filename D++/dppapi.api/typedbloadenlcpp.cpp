enum typeload
{
    MOVRDX,
    MOVEAX,
    MOVCL0
};

void lodbuf()
{
    typeload tl;
    tl::MOVRDX;
}

#include <windows.h>

void buffer()
{
    WINCLASS wc;
    wc.load          = IntroPartLoader(nullptr);
};
