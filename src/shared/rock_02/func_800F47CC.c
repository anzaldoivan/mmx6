#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
extern s16 D_800970AA;
#define D_800970AA (*(u16*)&D_800970AA)
extern s32 D_800FB308;
extern s32 D_800FB314;

void func_800F47CC(void* arg0) {
    void* parent;
    u8 t;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 2) == 9) {
        if (M2C_FIELD(arg0, u8*, 0x8D) >= 0xB) {
            if (M2C_FIELD(parent, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s16*, 0xA) = D_800970AA - 0x30;
                M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
            } else {
                M2C_FIELD(arg0, s16*, 0xA) = D_800970AA + 0x30;
                M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
            }
        }
    } else if (M2C_FIELD(arg0, u8*, 0x8D) >= 0xB) {
        if (M2C_FIELD(parent, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s16*, 0xA) = D_800970AA - 0x30;
            M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
        } else {
            M2C_FIELD(arg0, s16*, 0xA) = D_800970AA + 0x30;
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
        }
    }
    t = M2C_FIELD(arg0, u8*, 0x8D);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x8D) = t - 1;
        M2C_FIELD(arg0, u8*, 3) ^= 1;
        return;
    }
    M2C_FIELD(arg0, void**, 0x54) = &D_800FB308;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FB314;
    M2C_FIELD(arg0, u8*, 3) = 1;
    M2C_FIELD(arg0, u8*, 0x8D) = 8;
    M2C_FIELD(arg0, u8*, 6)++;
}
#undef D_800970AA
