#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_8008EAFC;
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
M2C_UNK func_8003D330();

void func_8005348C(struct X4_MainObj* arg0) {
    if (*(u16*)&arg0->bg_offset != 0) {
        D_800970A0.unk71 |= 8;
    }
    if (D_8008EAFC == 0) {
        if (arg0->unk2 & 0xF0) {
            D_800CCED0.unk10 = 0;
        }
        D_800CCED0.unk12 = 0;
        D_800CCED0.unk13 = 0;
        D_800CCED0.unk16 = 0;
        D_800CCED0.unk11 = 0;
        D_800CCED0.unk19 = 0;
        D_800CCED0.unk18 = 0;
        D_800CCED0.unk17 = 0;
        D_800CCED0.unk14 = 0;
        D_800CCED0.unk15 = 0;
        func_8003D330();
        arg0->state++;
    }
}
