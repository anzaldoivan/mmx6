#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
extern M2C_UNK D_800F6F40;
extern M2C_UNK D_800F6F50;

void func_800F39B0(void* arg0) {
    func_80017A04();
    ((void (*)(void*))move_object)(arg0);
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0) {
        set_animation(arg0, 1);
        play_sound(2, 0x74, arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800F6F50;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6F40;
        M2C_FIELD(arg0, s8*, 7) = -1;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
