#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
void func_800FA140(void* arg0);
extern s32 D_800FD5A0;

void func_800F7C74(void* arg0) {
    void* s1;
    s16 v;

    s1 = M2C_FIELD(arg0, void**, 0x84);
    func_80017A04(arg0);
    func_800FA140(arg0);
    v = M2C_FIELD(s1, s16*, 0x7C);
    if (v == 0) {
        s32 d;
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            register s32 c asm("$4");
            d = D_800FD5A0;
            c = M2C_FIELD(arg0, u8*, 6);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            d = -d;
            M2C_FIELD(arg0, s32*, 0x24) = d;
            M2C_FIELD(arg0, u8*, 6) = c + 1;
            return;
        }
    } else if (v == 1) {
        s32 d;
        if (M2C_FIELD(arg0, s8*, 0x8F) == 2) {
            d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = d;
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
    } else if (v == 2) {
        s32 d;
        if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
            d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = d;
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
    } else if (v == 3) {
        s32 d;
        if (M2C_FIELD(arg0, s8*, 0x8F) == 1) {
            d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -d;
            M2C_FIELD(arg0, u8*, 6)++;
            return;
        }
    } else if ((u16)(M2C_FIELD(s1, u16*, 0x7C) - 4) >= 2) {
        return;
    }
    M2C_FIELD(s1, u8*, 7)++;
    M2C_FIELD(arg0, s8*, 5) = 5;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, s16*, 0x7E) = 0;
}
