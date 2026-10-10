#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

void func_80025FD8();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s16 D_8009721E;
extern struct X4_EngineObj D_800CCED0;

void func_800F21B0(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0 &&
        ((D_800970A0.unk15 == 0 &&
          D_8009721E + 0x48 >= D_800970A0.x_pos.i.hi) ||
         (D_800970A0.unk15 == 0x40 &&
          D_800970A0.x_pos.i.hi >= D_8009721E + 0x18))) {
        func_8003D308(0x14, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
    if (*M2C_FIELD(SPAD4C, s8**, 0x80) == 0) {
        D_800CCED0.enable_boss = 1;
        D_800CCED0.unk25 = 0;
        D_800CCED0.boss_ptr = arg0;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            M2C_FIELD(&D_800CCED0, s8*, 0x8C) = 0x20;
        } else {
            M2C_FIELD(&D_800CCED0, s8*, 0x8C) = 0x30;
            if (M2C_FIELD(&D_800CCED0, u8*, 0x8F) != 0) {
                if (M2C_FIELD(&D_800CCED0, u8*, 0x8F) == 1) {
                    M2C_FIELD(&D_800CCED0, s8*, 0x8C) = 0x34;
                } else if (M2C_FIELD(&D_800CCED0, u8*, 0x8F) == 2) {
                    M2C_FIELD(&D_800CCED0, s8*, 0x8C) = 0x38;
                } else {
                    M2C_FIELD(&D_800CCED0, s8*, 0x8C) = 0x40;
                }
            }
        }
        func_80025FD8();
        {
            s32 k = 0xFFFF0000;
            M2C_FIELD(arg0, s32*, 0x24) = k;
            k = 1;
            M2C_FIELD(arg0, s8*, 3) = k;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
#undef D_800970A0
