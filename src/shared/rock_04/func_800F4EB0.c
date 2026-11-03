#include "common.h"

#define M2C_UNK s32

M2C_UNK start_pad_vibration(M2C_UNK);        /* extern */
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK apply_object_motion();               /* extern */

void func_800F4EB0(u8* arg0) {
    ((void (*)(void*))apply_object_motion)(arg0);
    if (arg0[0x70] & 8) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x12, arg0);
        ((void (*)(s32))start_pad_vibration)(8);
        arg0[6]++;
    }
}
