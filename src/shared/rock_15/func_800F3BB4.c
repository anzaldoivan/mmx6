#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 random_byte();
void func_800F3824(struct X4_MainObj*);

void func_800F3BB4(u8* arg0) {
    u8 r;

    func_80017A04();
    func_800F3824((struct X4_MainObj*)arg0);
    *(s32*)(arg0 + 0x28) = 0;
    *(s32*)(arg0 + 0x2C) = 0;
    if (arg0[0x15] == 0) {
        *(s32*)(arg0 + 0x20) = -0x8000;
    } else {
        *(s32*)(arg0 + 0x20) = 0x8000;
    }
    *(s32*)(arg0 + 0x24) = 0;
    r = (u32)random_byte() % 5;
    arg0[6] = arg0[6] + 1;
    *(s16*)(arg0 + 0x8C) = (r << 5) + 0xC0;
}
