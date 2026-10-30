#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK); /* extern */

void func_800EEAC4(void* arg0) {
    play_bgm_xa_track(6, 0x7F);
    M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
}
