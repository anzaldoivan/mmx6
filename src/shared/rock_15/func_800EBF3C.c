#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80017A04();
extern s16 D_800970AA;

void func_800EBF3C(void* arg0) {
    s16 a;
    s16 b;
    s32 d;

    ((void (*)())func_80017A04)();
    a = D_800970AA;
    b = M2C_FIELD(arg0, s16*, 0xA);
    d = a - b;
    if (d >= 0) {
        if (d < 0x90) {
            goto set;
        }
        return;
    }
    if (b - a < 0x90) {
    set:
        M2C_FIELD(arg0, u8*, 5) = 3;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
