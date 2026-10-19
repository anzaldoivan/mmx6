#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_80097424;

void func_800FA200(u8* arg0) {
    if (D_80097424 == 0) {
        D_800971F8[2].unk3 = 1;
        D_800971F8[1].unk3 = 1;
        func_80016C48(0, 0, 0);
        *(s16*)(arg0 + 8) = 0;
        *(s16*)(arg0 + 0xA) = 5;
        arg0[1]++;
    }
}
