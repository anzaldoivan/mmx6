#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCR_9C (*(s32**)0x1F80009C)
#define SCR_20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
void* enemy_slot_alloc();
extern s8 D_800CCEDC;

void func_800F765C(void* arg0, u8 arg1) {
    void* p;

    p = enemy_slot_alloc();
    if (p != 0) {
        M2C_FIELD(p, u8*, 0) = 0x41;
        M2C_FIELD(p, u8*, 1) = 0x33;
        M2C_FIELD(p, u8*, 0x15) = 0;
        M2C_FIELD(p, u8*, 2) = arg1;
        M2C_FIELD(p, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
        M2C_FIELD(p, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        M2C_FIELD(p, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(p, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(p, s16*, 0x40) = 0x540;
        if (D_800CCEDC == 0xC) {
            M2C_FIELD(p, s16*, 0x42) = 0x794C;
            M2C_FIELD(p, void**, 0x3C) = (u8*)SCR_9C + SCR_9C[1];
        } else {
            M2C_FIELD(p, s16*, 0x42) =
                (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 1) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(p, s8*, 1)) + 9) / 4 + 0x1E0) << 6);
            M2C_FIELD(p, void**, 0x3C) =
                (u8*)SCR_20 + SCR_20[func_8002A47C(M2C_FIELD(p, s8*, 1)) + 1];
        }
        M2C_FIELD(p, void**, 0x80) = arg0;
    }
}
#undef SCR_9C
#undef SCR_20
