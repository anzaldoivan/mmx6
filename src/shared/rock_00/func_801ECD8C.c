#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

void func_801ECD8C(void* arg0) {
    s32 v;

    v = *(u8*)((u8*)arg0 + 0xE1) + 1;
    *(u8*)((u8*)arg0 + 0xE1) = v;
    if ((u32)(v & 0xFF) >= 0x3C) {
        D_800CCED0.unk16 = 0;
        D_800CCED0.unk12 = 0;
        D_800CCED0.unk13 = 0;
        D_800CCED0.unk19 = 0;
        D_800CCED0.unk18 = 0;
        D_800CCED0.unk17 = 0;
        D_800CCED0.unk14 = 0;
        D_800CCED0.unk15 = 0;
        D_800CCED0.gameplay_locked = 0;
        *(u8*)((u8*)arg0 + 6) = *(u8*)((u8*)arg0 + 6) + 1;
    }
}
