#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void func_8003B954(struct X4_PlayerObj* self);
M2C_UNK func_8003BA04(void*, M2C_UNK);
extern u8 D_800CD40C;

void func_80038144(void* arg0) {
    ((void (*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if (D_800CD40C == 0) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0x27);
            M2C_FIELD(arg0, u8*, 6)++;
        }
    } else {
        if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
            M2C_FIELD(arg0, u8*, 0x45) = 0;
            play_sound(0, 0x21, 0);
        }
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            func_8003BA04(arg0, 0x28);
            func_8003B954(arg0);
        }
    }
}
