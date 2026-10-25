#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
s32 func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern s32 g_Player;
extern s16 D_800970AA;
extern s8 D_800CCF5C;
extern s32 D_800F6BF8;
extern s32 D_800F6BFC;
extern void* D_800F6C08;

void func_800F2348(void* arg0) {
    s32 x;
    s32* pl;

    if (D_800F6BF8 != 0 || D_800F6BFC != 0) {
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    if (func_80031474(arg0) < 0 || M2C_FIELD(arg0, u8*, 0x70) != 0 ||
        func_80030ECC(arg0) != 0) {
        func_80049E50(arg0);
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    switch (M2C_FIELD(arg0, s8*, 5)) {
    case 0:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x18) {
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x8C) = 0;
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 1:
        if (++M2C_FIELD(arg0, s32*, 0x8C) == 0x28) {
            func_80016C48(2, 0x3C, arg0);
            if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
            if (M2C_FIELD(D_800F6C08, s8*, 0x5C) > D_800CCF5C) {
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                } else {
                    M2C_FIELD(arg0, s32*, 0x20) = -0x30000;
                }
            } else if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s32*, 0x20) = 0x40000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = -0x40000;
            }
            M2C_FIELD(arg0, u8*, 5)++;
        }
        break;
    case 2:
        pl = &g_Player;
        x = M2C_FIELD(arg0, s32*, 0xC);
        if (x < pl[3]) {
            M2C_FIELD(arg0, s32*, 0xC) = x + 0x8000;
            if (pl[3] < x + 0x8000) {
                M2C_FIELD(arg0, s32*, 0xC) = pl[3];
            }
        } else if (pl[3] < x) {
            M2C_FIELD(arg0, s32*, 0xC) = x - 0x8000;
            if (x - 0x8000 < pl[3]) {
                M2C_FIELD(arg0, s32*, 0xC) = pl[3];
            }
        }
        break;
    }
    func_8002CCB0(arg0, 0x20, 0x10);
    func_80017A04(arg0);
    func_8002D230(arg0);
}
