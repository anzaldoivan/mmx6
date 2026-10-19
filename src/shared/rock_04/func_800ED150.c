#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800ED150(void* arg0) {
    struct X4_BackgroundObj* bg;
    // !FAKE: value lives in the first argument register as in the target
    register s32 v asm("$4");

    if (M2C_FIELD(arg0, s16*, 0xA) < 0x14C0) {
        if (D_800970A0.y_pos.i.hi >= 0x5C1 && D_800970A0.x_pos.i.hi >= 0x1411) {
            bg = D_800971F8;
            v = 0x1370;
            // !FAKE: shared store block as in the target
            goto store;
        }
    } else if (D_800970A0.y_pos.i.hi >= 0x5D1 &&
               D_800970A0.x_pos.i.hi >= 0x14E1) {
        bg = D_800971F8;
        v = 0x14D0;
    store: {
        // !FAKE: the state constant loads before the stores as in the target
        register s32 n asm("$3") = 9;
        bg->unk26 = v;
        bg->unk24 = v;
        M2C_FIELD(arg0, u8*, 6) = n;
    }
    }
}
