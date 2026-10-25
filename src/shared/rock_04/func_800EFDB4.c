#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
extern void (*D_800F6DD8[])(void*);

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))

void func_800EFDB4(void* arg0) {
    u16 x;

    D_800F6DD8[SB(arg0, 5)](arg0);
    if (func_80031474(arg0) < 0) {
        // !FAKE: depin: dropping it breaks the match (45/49)
        register s32 c asm("$3") = 2;
        x = UH(arg0, 0xA);
        SB(arg0, 4) = c;
        UH(arg0, 0x7C) = 0x3C;
        SB(arg0, 3) = 1;
        UH(arg0, 0x82) = x;
        UH(arg0, 0x80) = x;
        UH(arg0, 0x42) &= 0x7FFF;
        return;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x80, 0x80) == 1 && (u32)(UB(arg0, 2) - 0xA) < 2) {
        SB(arg0, 4) = 3;
    }
}
