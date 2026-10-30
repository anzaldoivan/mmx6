#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139F4(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_80097420;
extern u16 D_800C4570;

void func_800ED188(u8* arg0) {
    s8* e = (s8*)&D_80097420;

    if (e[4] == 0) {
        if (D_800C4570 & 0x40) {
            play_sound(0, 0x22, 0);
            arg0[1] = arg0[1] + 1;
            *(s16*)(arg0 + 0xA) = (u8)e[7];
            return;
        }
        if (D_800C4570 & 0x10) {
            ((void (*)(s32))func_800139F4)(8);
            *(s16*)(arg0 + 0xA) = 2;
            arg0[1] = arg0[1] + 1;
        }
    }
}
