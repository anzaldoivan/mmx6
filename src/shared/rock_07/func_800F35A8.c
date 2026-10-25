#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
s32 func_8002D2D4();                   /* extern */
extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern s32 D_800F9788;
extern void* D_800F9878;

void func_800F35A8(void* arg0) {
    s32 type;
    s8 sub;
    s8 one;
    s32 r;

    one = M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 4);
    if (one != 1) {
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 3) = 0;
        return;
    }
    sub = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s8*, 0x60) = 0;
    M2C_FIELD(arg0, s8*, 0x5C) = one;
    M2C_FIELD(arg0, s8*, 0x16) = 4;
    M2C_FIELD(arg0, s8*, 0x67) = one;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
    M2C_FIELD(arg0, s8*, 4) = one;
    M2C_FIELD(arg0, s8*, 5) = 0;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 7) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s8*, 0x94) = 0;
    type = sub & 0xF0;
    M2C_FIELD(arg0, s8*, 0x96) = 0;
    if (type == 0) {
        func_800179A4(arg0, 9);
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        {
            // !FAKE: depin: dropping it breaks the match (139/141)
            register s32 dir asm("$2");
            dir = M2C_FIELD(arg0, u8*, 0x15);
            if (dir == 0) {
                M2C_FIELD(arg0, u16*, 0xA) -= 0x20;
            } else {
                M2C_FIELD(arg0, u16*, 0xA) += 0x20;
            }
        }
        M2C_FIELD(arg0, s8*, 5) = 1;
    } else if (type == 0x10) {
        M2C_FIELD(arg0, s8*, 0x60) = 0;
        M2C_FIELD(arg0, s8*, 0x5C) = one;
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s8*, 5) = 0;
    } else if (type == 0x20) {
        M2C_FIELD(arg0, s8*, 0x60) = 0;
        M2C_FIELD(arg0, s8*, 0x5C) = one;
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        M2C_FIELD(arg0, s8*, 5) = 2;
    } else if (type == 0x30) {
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        if (sub == type) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 0x17);
            D_800F9878 = arg0;
            M2C_FIELD(arg0, s8*, 0x16) = 4;
            if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                M2C_FIELD(arg0, u16*, 0xA) -= 0x90;
                M2C_FIELD(arg0, u16*, 0xE) += 0x2D;
            } else {
                M2C_FIELD(arg0, u16*, 0xA) += 0x90;
                M2C_FIELD(arg0, u16*, 0xE) += 0x2D;
            }
            M2C_FIELD(arg0, s8*, 5) = 3;
        } else {
            M2C_FIELD(arg0, s32**, 0x50) = &D_800F9788;
            M2C_FIELD(arg0, s8*, 5) = 4;
        }
    } else if (type == 0x40) {
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        func_800179A4(arg0, 0x14);
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        M2C_FIELD(arg0, s8*, 5) = 5;
    } else if (type == 0x50) {
        M2C_FIELD(arg0, s8*, 0x96) = one;
        func_800179A4(arg0, 0x1B);
        r = func_8002D2D4();
        M2C_FIELD(arg0, s32**, 0x58) = D_800741FC;
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        M2C_FIELD(arg0, s8*, 0x5C) = one;
        M2C_FIELD(arg0, s8*, 0x16) = 4;
        M2C_FIELD(arg0, s8*, 5) = 6;
        M2C_FIELD(arg0, s8*, 2) = (u8)M2C_FIELD(arg0, s8*, 2) + (r & 3);
    }
}
