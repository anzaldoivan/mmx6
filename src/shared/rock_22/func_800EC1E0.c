#include "common.h"

#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, u8);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800EC1E0(void* arg0) {
    if (D_800970A0.x_pos.i.hi >= 0x1C21) {
        D_800971F8[0].unk26 = 0x1B70;
        D_800971F8[0].unk2A = 0x1E0;
        D_800971F8[0].unk28 = 0x1E0;
        func_8003D308(0x14, D_800970A0.unk15);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
