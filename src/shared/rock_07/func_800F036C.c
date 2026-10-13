#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern s8 D_80097244;
extern s32 D_800F8DD8;

void func_800F036C(void* arg0) {
    s16 rect[4];
    s8 state;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(arg0, u8*, 0) |= 0x10;
    func_80017A04(arg0);
    if (func_80031474(arg0) < 0) {
        M2C_FIELD(arg0, u8*, 3) = 0;
        rect[0] = M2C_FIELD(arg0, u16*, 0xA) - 0x10;
        rect[1] = M2C_FIELD(arg0, u16*, 0xE) + 0x1F0;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            rect[2] = 2;
        } else {
            rect[2] = 1;
        }
        rect[3] = 1;
        func_80027BA0(0, M2C_FIELD(arg0, s16*, 0xA) - 0x10,
                      M2C_FIELD(arg0, s16*, 0xE) - 0x10, (u8*)rect);
        D_80097244 = 1;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            func_800477E4(5, &D_800F8DD8, arg0);
        } else {
            M2C_FIELD(arg0, u16*, 0xA) -= 8;
            func_800477E4(3, &D_800F8DD8, arg0);
        }
        state = 2;
    } else {
        if (func_8002CBFC(arg0, 0x30, 0x30) == 0) {
            func_8002CCB0(arg0, 0x20, 0x20);
            return;
        }
        state = 3;
    }
    M2C_FIELD(arg0, u8*, 4) = state;
}
