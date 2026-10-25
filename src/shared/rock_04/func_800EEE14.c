#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
extern s32 D_800F6C50[];
extern s32 D_800F6C58[];

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EEE14(void* arg0) {
    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (31/35)
        register s32 t asm("$2") = H(arg0, 0x7C);
        if (t != 0) {
            W(arg0, 0x54) = 0;
            W(arg0, 0x50) = 0;
            H(arg0, 0x7C)--;
            UB(arg0, 3) ^= 1;
            return;
        }
    }
    UB(arg0, 5) = 1;
    UB(arg0, 3) = 1;
    W(arg0, 0x54) = (s32)&D_800F6C58[UB(arg0, 0x80)];
    W(arg0, 0x50) = (s32)&D_800F6C50[UB(arg0, 0x80)];
}
