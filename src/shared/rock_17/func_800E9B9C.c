#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK); /* extern */
extern s8 D_80097424;

void func_800E9B9C(void* arg0) {
    if (D_80097424 == 0) {
        M2C_FIELD(arg0, s16*, 4) = 0;
        M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
        play_bgm_xa_track(3, 0x7F);
    }
}
