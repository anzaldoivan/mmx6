#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F2BE4(void* arg0) {
    s32 ang;

    D_800970A0.spike_immune = 1;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    if (D_800970A0.unk5 == 0x14) {
        func_800179A4(arg0, 2);
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        if (D_800971F8[0].unk1E + 0x50 < D_800970A0.x_pos.i.hi) {
            func_8003D308(0x1D, 0);
        } else {
            func_8003D308(0x1D, 0x40);
        }
        ang = func_80065B74(
            (s16)(D_800971F8[0].unk22 + 0x60) - M2C_FIELD(arg0, s16*, 0xE),
            (s16)(D_800971F8[0].unk1E + 0x100) - M2C_FIELD(arg0, s16*, 0xA));
        M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(ang) * 0x10;
        M2C_FIELD(arg0, s32*, 0x24) = -func_80065944(ang) * 0x10;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        SPAD4C[0x88] = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef D_800970A0
