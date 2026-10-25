#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_80017A04();                        /* extern */
void* func_8002C32C();                          /* extern */
extern M2C_UNK g_Player;
extern s8 D_800970FC;

void func_800F04E8(void* arg0) {
    s32 f;
    u16 b;
    void* o;

    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x80) {
            func_80016C48(2, 0x25, 0);
            f = 1;
        } else {
            goto block_4;
        }
    } else {
        f = 1;
        if (D_800970FC != -0x80) {
        block_4:
            f = 0;
        }
    }
    if (f != 0) {
        M2C_FIELD(arg0, u8*, 5) = 0xB;
        M2C_FIELD(arg0, u8*, 6) = 0;
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        if (!(M2C_FIELD(arg0, u8*, 0xA8) & 8)) {
            M2C_FIELD(arg0, u8*, 5) = 0xC;
            M2C_FIELD(arg0, u8*, 6) = 0;
        } else {
            b = M2C_FIELD(arg0, u16*, 0x88);
            if (b & 2) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else if (b & 1) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            if (!(M2C_FIELD(arg0, u8*, 0x97) & 0x10) &&
                M2C_FIELD(arg0, u8*, 0x94) == 0) {
                M2C_FIELD(arg0, u8*, 6) = 2;
                M2C_FIELD(arg0, u16*, 0x98) = 0x420;
                if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
                    M2C_FIELD(arg0, s32*, 0x20) = 0xFFFBE000;
                } else {
                    M2C_FIELD(arg0, s32*, 0x20) = 0x42000;
                }
                M2C_FIELD(arg0, u8*, 0x90) = 0x1E;
                o = func_8002C32C();
                if (o != 0) {
                    M2C_FIELD(o, u8*, 0) = 0x41;
                    M2C_FIELD(o, u8*, 1) = 0x3E;
                    M2C_FIELD(o, u8*, 2) = 4;
                    M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
                    M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
                    M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                    M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                    M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                    M2C_FIELD(o, u16*, 0x42) =
                        M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                    M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
                    M2C_FIELD(o, void**, 0x7C) = arg0;
                    M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                }
                ((void (*)(void*, s32))func_800179A4)(arg0, 0xF);
                if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
                    void* pl = &g_Player;
                    M2C_FIELD(pl, u8*, 0xD8) = 0x36;
                    M2C_FIELD(pl, u8*, 6) = 0;
                }
                if (M2C_FIELD(arg0, s8*, 2) == 0) {
                    func_80016C48(2, 0x2D, 0);
                } else {
                    func_80016C48(2, 6, 0);
                }
            }
        }
        ((void (*)(void*))func_80017A04)(arg0);
        return;
    }
    ((void (*)(void*))func_80017A04)(arg0);
}
