#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_80030CCC(void*, s32, s32, s16);
extern s8 D_80097244;
extern u8 D_800F6C00[];
extern void* D_800F6C08;

void func_800EC4DC(void* arg0) {
    func_80017A04();
    {
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 0x84) + 1;
        M2C_FIELD(arg0, u8*, 0x84) = t;
        if ((u8)t == 0x20) {
            if (M2C_FIELD(arg0, s8*, 2) == 0xB) {
                if (!(((s32(*)())func_80030CCC)(
                          arg0, M2C_FIELD(arg0, s16*, 0xA),
                          M2C_FIELD(arg0, s16*, 0xE) - 0x1A) &
                      0xFF)) {
                    func_800179A4(arg0, 2);
                } else {
                    func_800179A4(arg0, 3);
                }
            } else {
                func_800179A4(arg0, 2);
            }
        }
    }
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        if (M2C_FIELD(arg0, s8*, 2) == 0xB) {
            if (!(((s32(*)())func_80030CCC)(arg0, M2C_FIELD(arg0, s16*, 0xA),
                                            M2C_FIELD(arg0, s16*, 0xE) - 0x1A) &
                  0xFF)) {
                func_80027BA0(0, M2C_FIELD(arg0, s16*, 0xA) - 0x18,
                              M2C_FIELD(arg0, s16*, 0xE) - 0x20, D_800F6C00);
            } else {
                func_80027BA0(0, M2C_FIELD(arg0, s16*, 0xA) - 0x18,
                              M2C_FIELD(arg0, s16*, 0xE) - 0x18,
                              (u8*)&D_800F6C08);
            }
        } else {
            func_80027BA0(0, M2C_FIELD(arg0, s16*, 0xA) - 0x18,
                          M2C_FIELD(arg0, s16*, 0xE) - 0x20, D_800F6C00);
        }
        D_80097244 = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
