#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s16 D_800970AA;

void func_800F93B8(struct X4_BaseObj* arg0) {
    if (D_800970AA >= 0x16C0) {
        ((void (*)(s32, s32))func_8003D308)(0x14, 0x40);
        ((void (*)(s32, s32, s32))open_text_box)(2, 0xFF, 0);
        arg0->unk5++;
    }
}
