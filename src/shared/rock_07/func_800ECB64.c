#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
void func_800EAA2C();

void func_800ECB64(void* arg0) {
    s8 t = M2C_FIELD(arg0, s8*, 0x45);

    if (t == 1) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB4;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        func_800EAA2C(arg0, 0x30);
    } else if (t == 2) {
        play_sound(2, 0x49, arg0);
    }
}
