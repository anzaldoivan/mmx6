#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
M2C_UNK func_8002CB50();
extern struct X4_BackgroundObj D_800971F8[3];
extern u16 D_800F1680[][2];
extern s8 D_800F1CCA[];

void func_800F0518(void* arg0) {
    s8 t;
    u16 v;

    t = *(s8*)((u8*)arg0 + 2);
    func_800179D0(arg0, t, D_800F1CCA[t]);
    v = D_800F1680[*(s8*)((u8*)arg0 + 2)][0];
    *(u16*)((u8*)arg0 + 0xA) = v;
    *(u16*)((u8*)arg0 + 0xE) = D_800F1680[*(s8*)((u8*)arg0 + 2)][1];
    if (D_800971F8[*(s8*)((u8*)arg0 + 0x14)].x_pos.i.hi < 0x400) {
        *(u16*)((u8*)arg0 + 0xA) = v - 0x600;
    }
    ((void (*)())func_8002CB50)(arg0);
}
