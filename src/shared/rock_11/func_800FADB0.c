#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800FD4F4[];

void func_800FADB0(void* arg0) {
    ((void (*)(void*))D_800FD4F4[M2C_FIELD(arg0, s8*, 6)])(arg0);
    if (M2C_FIELD(arg0, s16*, 0x54) != 0) {
        M2C_FIELD(arg0, s16*, 0x54)--;
        if (M2C_FIELD(arg0, s16*, 0x54) & 1) {
            M2C_FIELD(arg0, s8*, 3) = 0;
        } else {
            M2C_FIELD(arg0, s8*, 3) = 1;
        }
        if (M2C_FIELD(arg0, s16*, 0x54) == 0) {
            M2C_FIELD(arg0, s8*, 3) = 1;
        }
    }
}
