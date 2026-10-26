#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F586C;
extern M2C_UNK D_800F5870;
extern M2C_UNK D_800F5874;
extern M2C_UNK D_800F5878;

void func_800EC41C(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x3) = 1;
    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        struct X4_PlayerObj* pl = &g_Player;
        s32 angle;
        s32 x;
        s32 t;
        s32 t2;
        angle = ratan2(M2C_FIELD(pl, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                       M2C_FIELD(pl, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
        t = rcos(angle) << 4;
        M2C_FIELD(arg0, s32*, 0x20) = (t * 2 + t) >> 1;
        t2 = -rsin(angle) << 4;
        M2C_FIELD(arg0, s32*, 0x24) = (t2 * 2 + t2) >> 1;
        x = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0xA) =
            (M2C_FIELD(arg0, u8*, 0x15) != 0) ? x + 0x12 : x - 0x12;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F5874;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F586C;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F586C;
        M2C_FIELD(arg0, u8*, 0x16) = 3;
        M2C_FIELD(arg0, s16*, 0xE) += 8;
        func_800179A4(arg0, 0x10);
    } else {
        u8 dir1;
        s32 x1;
        dir1 = M2C_FIELD(arg0, u8*, 0x15);
        x1 = -0x18000;
        if (dir1 != 0) {
            x1 = 0x18000;
        }
        M2C_FIELD(arg0, s32*, 0x20) = x1;
        x1 = M2C_FIELD(arg0, s16*, 0xA);
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        if (dir1 != 0) {
            x1 += 3;
        } else {
            x1 -= 3;
        }
        M2C_FIELD(arg0, s16*, 0xA) = x1;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F5878;
        M2C_FIELD(arg0, void**, 0x54) = &D_800F5870;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F5870;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        func_800179A4(arg0, 0xB);
    }
    M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x4) += 1;
}
