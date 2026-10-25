#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230();

#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800F96E0(void* arg0) {
    u8 t;

    func_8002D230(arg0);
    t = F8(arg0, 0x15);
    if (t == 0) {
        if (F8(arg0, 0x70) & 1) {
            goto block_5;
        }
    }
    if (t == 0x40 && (F8(arg0, 0x70) & 2)) {
    block_5:
        func_80016C48(2, 0x4E, arg0);
        func_80012D9C(5);
        func_8002943C(0x14, 6, 2);
        {
            // !FAKE: depin: dropping it breaks the match (35/40)
            register s32 b asm("$2") = F8(arg0, 6);
            F16(arg0, 0x7C) = 0x1E;
            F8(arg0, 6) = b + 1;
        }
    }
}
