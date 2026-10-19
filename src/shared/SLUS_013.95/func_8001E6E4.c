#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
extern void (*D_8007112C[])(struct X4_EngineObj*);
void func_80013360(s32);

void func_8001E6E4(void) {
    while (1) {
        s32 i = D_800CCED0.state;
        D_8007112C[i](&D_800CCED0);
        func_80013360(1);
    }
}
