#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80037A60(void* arg0);        /* extern */
void func_8003AD18(void* arg0);        /* extern */
M2C_UNK func_8003AFF4(s32);            /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
void func_8003D014(void* arg0);        /* extern */
void func_8003D394(void* arg0);        /* extern */
extern u8 D_800CCF2F;

void func_80035BDC(void* arg0) {

    func_80037A60(arg0);
    func_8003D394(arg0);
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    if ((M2C_FIELD(arg0, s8*, 0x67) != 0) && (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        if (!(M2C_FIELD(arg0, s32*, 0xEC) & 0x200) &&
            ((M2C_FIELD(arg0, s8*, 2) == 0) || !(D_800CCF2F & 0x20))) {
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
            }
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x61) == 0x3C) {
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            M2C_FIELD(arg0, u8*, 0x67) = 0;
            func_8003AD18(arg0);
        } else if (M2C_FIELD(arg0, s32*, 0x2C) != 0) {
            func_8003BA04(arg0, 0xB);
            {
                register s32 m1 asm("$2") = -1;
                register s32 k7 asm("$3") = 7;
                M2C_FIELD(arg0, s8*, 0x67) = m1;
                M2C_FIELD(arg0, u8*, 5) = k7;
            }
            M2C_FIELD(arg0, u8*, 6) = 0;
        } else {
            func_8003AFF4((s32)arg0);
        }
        if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
            M2C_FIELD(arg0, u8*, 0xA4) = 0;
            M2C_FIELD(arg0, u8*, 0x61) = 0;
            return;
        }
        func_8003D014(arg0);
        M2C_FIELD(arg0, s8*, 0xA4) = -1;
    }
}
