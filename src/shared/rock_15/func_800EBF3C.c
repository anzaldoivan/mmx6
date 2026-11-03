#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK animate_object();
extern s16 D_800970AA;

void func_800EBF3C(void* arg0) {
    s16 a;
    s16 b;
    s32 d;

    ((void (*)())animate_object)();
    a = D_800970AA;
    b = M2C_FIELD(arg0, s16*, 0xA);
    d = a - b;
    if (d >= 0) {
        if (d < 0x90) {
            // !FAKE: goto keeps the two-sided range test arms (C0144); duplicating the arm moved bytes
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
