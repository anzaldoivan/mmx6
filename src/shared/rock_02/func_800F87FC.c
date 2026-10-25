#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern M2C_UNK D_800FB310;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F87FC(void* arg0) {
    void* t;
    s32 e;
    s32 e2;

    ((M2C_UNK(*)())func_80017A04)();
    t = P(arg0, 0x7C);
    if (SB(arg0, 0x45) == 1) {
        P(arg0, 0x50) = &D_800FB310;
    }
    if (SB(t, 0x45) == 1) {
        H(arg0, 0xA) = H(t, 0xA);
        e = UH(t, 0xE) - 0x18;
        UB(arg0, 0x16) = 6;
        H(arg0, 0xE) = e;
    } else {
        if (UB(t, 0x15) == 0) {
            H(arg0, 0xA) = H(t, 0xA) - 0x30;
        } else {
            H(arg0, 0xA) = H(t, 0xA) + 0x30;
        }
        e2 = UH(t, 0xE) - 8;
        UB(arg0, 0x16) = 4;
        H(arg0, 0xE) = e2;
    }
    {
        // !FAKE: depin: dropping it breaks the match (62/64)
        register s32 two asm("$4");
        s32 c = SB(t, 0x6);
        two = 2;
        if (c >= 6) {
            P(arg0, 0x50) = 0;
            H(arg0, 0x90) = 0;
            UB(arg0, 0x47) = 0xE;
            UB(arg0, 0) |= 0x10;
            func_80016C48(two, 0x14, arg0);
            UB(arg0, 0x6)++;
        }
    }
}
