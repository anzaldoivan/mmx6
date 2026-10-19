#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800EB87C(void* arg0) {
    struct X4_BackgroundObj* bg = D_800971F8;

    bg[1].y_pos.u.hi -= 8;
    if (bg[1].y_pos.i.hi < 0x339) {
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x44, arg0);
        ((void (*)(s32))func_80012D9C)(5);
        ((void (*)(s32, s32, s32))func_80029478)(6, 0xA, 2);
        bg[1].y_pos.i.hi = 0x338;
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
