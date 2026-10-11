#include "common.h"

s32 func_8002D30C();
void func_800328B0();
s32 func_80065944(s32);
s32 func_80065A14(s32);
extern s32 D_80078268[];
extern s32 D_80078278[];

#define C120_W(p, o) (*(s32*)((u8*)(p) + (o)))
#define C120_B(p, o) (*(u8*)((u8*)(p) + (o)))
#define C120_H(p, o) (*(u16*)((u8*)(p) + (o)))

void func_8004C120(void* arg0) {
    s32 r;

    C120_W(arg0, 0x1C) = func_80065A14(C120_H(arg0, 0x38)) *
                         D_80078268[C120_B(arg0, 0x3A) + 1] * 0x10;
    C120_W(arg0, 0x20) = func_80065944(C120_H(arg0, 0x38)) *
                         D_80078268[C120_B(arg0, 0x3A) + 1] * 0x10;
    C120_W(arg0, 0x24) =
        func_80065A14((C120_H(arg0, 0x38) + D_80078278[func_8002D30C() % 3]) &
                      0xFFF) *
        D_80078268[C120_B(arg0, 0x3A)] * 0x10;
    C120_W(arg0, 0x28) =
        func_80065944((C120_H(arg0, 0x38) + D_80078278[func_8002D30C() % 3]) &
                      0xFFF) *
        D_80078268[C120_B(arg0, 0x3A)] * 0x10;
    C120_W(arg0, 0x2C) = 0;
    C120_W(arg0, 0x30) = 0;
    r = func_8002D30C();
    C120_B(arg0, 0x4)++;
    C120_B(arg0, 0x3B) = r % 7;
    func_800328B0(arg0);
}

#undef C120_W
#undef C120_B
#undef C120_H
