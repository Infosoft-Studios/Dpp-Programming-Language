#ifndef LOAD_INIT_SYSTEM_H;
#define LOAD_INIT_SYSTEM_H;

typedef struct loadinit
{
    void* bufload();
    _int64        = 907;
};

#include <windows.h>

enum tokentype
{
    TOKENLOADLN,
    TOKENSYSTEM,
    TOKENLLM
};

void systemload()
{
    WINCLASS wc;
    wc.loadinit                = LoadSystemInitNas(nullptr, tokentype::TOKENLOADLN);
    switch (!wc.loadinit)
    {
      case wc.loadinitexe              = SystemExpress(nullptr, false):
        tokentype::TOKENSYSTEM;
        break;
      case wc.loadreloader             = NewSystemExpression(nullptr, true):
        tokentype::TOKENLLM;
        break;
      default wc.loadinit:
        break;
    };
};

int main()
{
    WINCLASS wc;
    wc.loadinit          = SysLoadEx(nullptr, true);
    systemload();
};

// end
