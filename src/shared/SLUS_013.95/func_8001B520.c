#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK SsSetSerialAttr(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80064C94(M2C_UNK*, u32);
extern u32 D_80070CC0;
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)
extern M2C_UNK D_800E2F3C;

void func_8001B520(void) {
    s32 i;
    s32 h;

    ((void (*)(M2C_UNK, M2C_UNK, M2C_UNK))SsSetSerialAttr)(0, 0, 1);
    if (D_800CC869 != 0) {
        i = 0;
        do {
            M2C_FIELD(&D_800E2F3C, s8*, 0) = i;
            M2C_FIELD(&D_800E2F3C, s8*, 1) = 0;
            M2C_FIELD(&D_800E2F3C, s8*, 2) = i;
            M2C_FIELD(&D_800E2F3C, s8*, 3) = 0;
            ((M2C_UNK(*)())func_80064C94)(&D_800E2F3C);
            i += 2;
        } while (D_80070CC0 >= i);
        return;
    }
    i = 0;
    do {
        h = i / 2;
        M2C_FIELD(&D_800E2F3C, s8*, 0) = h;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = h;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = h;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = h;
        ((M2C_UNK(*)())func_80064C94)(&D_800E2F3C);
        i += 2;
    } while (D_80070CC0 >= i);
}
#undef D_800CC869
