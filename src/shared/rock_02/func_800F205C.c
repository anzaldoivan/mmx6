#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

void* func_8002C3F8();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_800FBC7C;

void func_800F205C(void* arg0) {
    void* child;
    s8 prev;

    if (D_800970A0.unk5 == 0x14) {
        child = func_8002C3F8();
        if (child != 0) {
            M2C_FIELD(child, u8*, 0) = 1;
            M2C_FIELD(child, u8*, 1) = 0x18;
            M2C_FIELD(SPAD4C, void**, 0x80) = child;
        }
        prev = D_800971F8[0].unk48;
        D_800971F8[0].unk48 = 1;
        D_800FBC7C = prev;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            D_800971F8[0].unk24 = 0x17B0;
            D_800971F8[0].unk26 = 0x17B0;
            D_800971F8[0].unk4C = 1;
        }
        M2C_FIELD(arg0, s16*, 0xA) = D_800971F8[0].unk26 + 0xF0;
        M2C_FIELD(arg0, s16*, 0xE) = D_800971F8[0].unk2A - 0x40;
        if (D_800970A0.x_pos.i.hi <= D_800971F8[0].unk26 + 0x40 &&
            D_800970A0.x_pos.i.hi >= D_800971F8[0].unk26 + 0x20) {
            M2C_FIELD(arg0, s16*, 0x7C) = 0;
        } else {
            M2C_FIELD(arg0, s16*, 0x7C) = 1;
            if (D_800970A0.x_pos.i.hi > D_800971F8[0].unk26 + 0x30) {
                func_8003D308(0x1D, 0);
            } else {
                func_8003D308(0x1D, 0x40);
            }
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
#undef D_800970A0
