#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_demo_xa_track(s16, M2C_UNK); /* extern */
extern u8 D_800CCF99;
extern u8 D_800CD40C;

void func_800EA324(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0xA) != 0) {
        if (D_800CCF99 & 0x10) {
            if (D_800CD40C == 0) {
                play_demo_xa_track(M2C_FIELD(arg0, s16*, 8), 0x7F);
                goto block_4;
            }
        } else {
        block_4:
            M2C_FIELD(arg0, u8*, 3) = (u8)(M2C_FIELD(arg0, u8*, 3) + 1);
        }
    }
}
