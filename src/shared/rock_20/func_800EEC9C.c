#include "common.h"
#define M2C_UNK s32

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);

void func_800EEC9C(u8* arg0) {
    ((void (*)(s32, s32, s32))open_text_box)(0, 0xFF, 0);
    arg0[2]++;
}
