#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);

#define PAL_BUF (*(u8**)0x1F800024)
#define PAL_BUF_B ((u8*)((struct X4_PlayerObj*)0x1F800000)->y_vel.val)

void func_8003CF54(struct X4_PlayerObj* self, s32 arg1) {
    if (self->unk2 == 0) {
        func_8002B3D4(0, (s32*)(PAL_BUF + (arg1 << 5)), 1);
        func_8002B3D4(0x13, (s32*)(PAL_BUF_B + ((arg1 + 1) << 5)), 1);
    } else {
        func_8002B3D4(0, (s32*)(PAL_BUF + (arg1 << 5)), 1);
    }
}
#undef PAL_BUF
#undef PAL_BUF_B
