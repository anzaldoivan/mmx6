#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern u16 D_8009721A;
extern u8 D_800FB810[];

void func_800F6B20(void* arg0) {
    s32 t;
    s32 v;

    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (s16)D_8009721A + 0x40) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x40;
        if (--M2C_FIELD(arg0, s16*, 0x7E) != 0) {
            set_animation(arg0, 7);
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
            M2C_FIELD(arg0, u8*, 6) = 1;
            return;
        }
        t = SPAD4C[0x85] + 1;
        SPAD4C[0x85] = t;
        v = D_800FB810[(t & 3) + SPAD4C[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}
