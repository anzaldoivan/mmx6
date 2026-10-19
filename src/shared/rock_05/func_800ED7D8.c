#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;

void func_800ED7D8(void* arg0) {
    struct X4_BackgroundObj* bg;

    if (!(D_80097420 & 3)) {
        func_80029478(3, 2, 1);
    }
    bg = D_800971F8;
    bg[2].y_pos.val += 0x8000;
    if (bg[2].y_pos.i.hi >= 0x6B0) {
        func_80016C48(5, 3, arg0);
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
