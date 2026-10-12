#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F52FC(u8* self) {
    u16 x;
    if (*(s8*)(self + 0x45) == 1) {
        x = D_800970A0.x_pos.i.hi;
        *(s16*)(self + 0x84) = x;
        *(s16*)(self + 0x86) = D_800970A0.y_pos.i.hi - 0x50;
        if ((s16)x < D_800971F8[0].unk26 + 0x28) {
            *(s16*)(self + 0x84) = D_800971F8[0].unk26 + 0x28;
        } else if (D_800971F8[0].unk26 + 0x138 < (s16)x) {
            *(s16*)(self + 0x84) = D_800971F8[0].unk26 + 0x138;
        }
        if (*(s16*)(self + 0x86) < D_800971F8[0].unk2A + 0x30) {
            *(s16*)(self + 0x86) = D_800971F8[0].unk2A + 0x30;
        }
        func_80016C48(2, 0x5B, self);
        self[6]++;
    }
}
