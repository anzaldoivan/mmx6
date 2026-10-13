#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_80071EE0[];
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800CD338;
extern u8 D_800CD339;
extern M2C_UNK D_800CD3F0;
#define D_800CD3F0 (*(u8(*)[4]) & D_800CD3F0)

void func_800280F4(void) {
    struct X4_BackgroundObj* bg;
    u32 i;
    u8* p;

    bg = D_800971F8;
    i = 0;
    do {
        bg->unk0 = 1;
        bg->unk3 = 1;
        bg->unk44 = 1;
        bg->pad51[1] = -1;
        bg->unk4D = 0;
        bg->min_y = 0;
        bg->unk4E = D_800CD338 - 1;
        bg->max_y = D_800CD339 - 1;
        bg++;
        i++;
    } while (i < 3);
    p = &D_80071EE0[D_800CCED0.stage * 20 + D_800CCED0.substage * 10];
    D_800CD3F0[0] = *p++;
    D_800CD3F0[1] = *p++;
    D_800CD3F0[2] = *p++;
    D_800CD3F0[3] = *p++;
    D_800971F8[0].unk4B = *p++;
    D_800971F8[0].unk4A = *p++;
    D_800971F8[1].unk4B = *p++;
    D_800971F8[1].unk4A = *p++;
    D_800971F8[2].unk4B = *p++;
    D_800971F8[2].unk4A = *p++;
}
#undef D_800CD3F0
