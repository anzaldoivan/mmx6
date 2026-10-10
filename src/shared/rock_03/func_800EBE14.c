#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

#define SP64 (*(u8**)(0x1F800064))
#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define P50(p) (*(u8**)((u8*)(p) + 0x50))

void func_800EBE14(u8* arg0) {
    s8 mode;
    u8 val;
    u8* par;

    mode = B(P50(arg0), 4);
    if (mode != 1) {
        B(arg0, 3) = 0;
        UB(arg0, 4) = UB(arg0, 4) + 1;
        return;
    }
    func_80017A04(arg0);
    par = P50(arg0);
    UB(arg0, 0x15) = UB(par, 0x15);
    UH(arg0, 0xA) = UH(par, 0xA);
    UH(arg0, 0xE) = UH(par, 0xE);
    val = UB(par, 0x88);
    if (UB(SP64, 0x54) != val) {
        if (val == mode) {
            goto same;
        }
        switch (val) {
        case 0:
            B(arg0, 3) = 0;
            break;
        same:
            B(arg0, 3) = val;
            func_800179A4(arg0, 1);
            break;
        case 1:
            break;
        case 2:
            B(arg0, 3) = mode;
            func_800179A4(arg0, 3);
            break;
        case 3:
            B(arg0, 3) = mode;
            func_800179A4(arg0, 5);
            break;
        }
    }
    UB(SP64, 0x54) = val;
}
