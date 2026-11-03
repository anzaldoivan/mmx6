#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK apply_object_motion();

void func_800F3BE0(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        play_sound(2, 0x12, arg0);
        ((void (*)(s32))start_pad_vibration)(8);
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
        return;
    }
    apply_object_motion(arg0);
}
