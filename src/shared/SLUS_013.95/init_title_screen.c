#include "common.h"
#define M2C_UNK s32

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK func_800139A0(s8);
void* alloc_sprite_slot();
extern u8 D_80071114[];

// 0x8001DEB8 init_title_screen: title screen voice.
// basis: community tweaks-index.tsv:331
// callers: none known
void init_title_screen(void* arg0) {
    u32 i;
    s8* o;

    for (i = 0; i < 1; i++) {
        o = alloc_sprite_slot();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0x13;
            o[2] = D_80071114[i];
        }
    }
    FX(arg0, s16, 4) = 0x258;
    FX(arg0, u8, 0xD) = 0;
    FX(arg0, u8, 1)++;
    ((void (*)(s8))func_800139A0)(8);
}
