#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
extern s8 D_800CCF5C;
extern s32 D_800FDE30;

void func_800FD17C(void* arg0) {
    void* p;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x87, arg0);
        if (M2C_FIELD(arg0, s8*, 0x5C) < D_800CCF5C / 2) {
            M2C_FIELD(arg0, u8*, 0x45) = 0;
            p = func_8002C458();
            if (p != 0) {
                u8 b = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(p, u8*, 1) = 0x13;
                M2C_FIELD(p, u8*, 2) = 5;
                M2C_FIELD(p, void**, 0x7C) = arg0;
                M2C_FIELD(p, u8*, 0) = b;
            }
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        set_animation(arg0, 0);
        {
            u8* t = (u8*)&D_800FDE30 + 0x284;
            u8* q = t + (M2C_FIELD(arg0, u8*, 0x87)++ +
                         M2C_FIELD(arg0, u8*, 0x86) * 6);
            M2C_FIELD(arg0, u8*, 5) = *q;
        }
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
