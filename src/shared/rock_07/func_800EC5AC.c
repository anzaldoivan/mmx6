#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern s8 D_80097180;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800EC5AC(void* arg0) {
    struct X4_BackgroundObj* bg;

    if (D_80097180 != 2) {
        bg = D_800971F8;
        bg[1].y_pos.val += 0xFFFC0000;
        if (bg[1].y_pos.i.hi < 0x309) {
            ((void (*)(s32, s32, void*))func_80016C48)(2, 0x44, arg0);
            ((void (*)(s32))func_80012D9C)(5);
            bg[1].y_pos.i.hi = 0x308;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
            M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        }
    }
}
