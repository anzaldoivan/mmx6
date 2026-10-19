#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj D_800970A0;

void func_800462C0(void* arg0) {
    struct X4_PlayerObj* p = &D_800970A0;

    if (p->unk5 != 0x2A) {
        M2C_FIELD(arg0, s8*, 0x91) = 1;
        M2C_FIELD(arg0, s8*, 0x4) = 3;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x8C) == 4) {
        p->unk6 = 1;
        M2C_FIELD(arg0, u8*, 0x5) += 1;
    }
}
