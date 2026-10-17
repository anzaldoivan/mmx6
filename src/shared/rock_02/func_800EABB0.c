#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);

#define ABB0_SP64 (*(u8**)(0x1F800064))
#define ABB0_UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define ABB0_SH(p, o) (*(s16*)((u8*)(p) + (o)))
#define ABB0_P(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800EABB0(u8* arg0) {
    u8* obj;
    u8 mode;

    obj = ABB0_P(arg0, 0x50);
    mode = ABB0_UB(obj, 0x83);
    if (ABB0_UB(obj, 0x47) == 0x17) {
        ABB0_SH(ABB0_SP64, 0x56) = -1;
    } else {
        ABB0_SH(ABB0_SP64, 0x56) = 0;
    }
    if (ABB0_UB(ABB0_SP64, 0x54) != mode) {
        switch (mode) {
        case 0:
            ABB0_UB(arg0, 3) = 0;
            break;
        case 1:
            ABB0_UB(arg0, 3) = mode;
            func_800179A4(arg0, 5);
            break;
        case 2:
            ABB0_UB(arg0, 3) = 1;
            func_800179A4(arg0, 2);
            break;
        }
    }
    ABB0_UB(ABB0_SP64, 0x54) = mode;
}
