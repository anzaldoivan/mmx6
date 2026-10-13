#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F5648(u8* self) {
    u16 x;
    if (*(s8*)(self + 0x45) == 1) {
        x = D_800970A0.x_pos.i.hi;
        *(s16*)(self + 0x84) = x;
        *(s16*)(self + 0x86) = D_800970A0.y_pos.i.hi - 0x70;
        if ((s16)x < D_800971F8[0].unk26 + 0x28) {
            *(s16*)(self + 0x84) = D_800971F8[0].unk26 + 0x28;
        } else if (D_800971F8[0].unk26 + 0x138 < (s16)x) {
            *(s16*)(self + 0x84) = D_800971F8[0].unk26 + 0x138;
        }
        if (*(s16*)(self + 0x86) < D_800971F8[0].unk2A + 0x30) {
            *(s16*)(self + 0x86) = D_800971F8[0].unk2A + 0x30;
        }
        self[6]++;
    }
}
