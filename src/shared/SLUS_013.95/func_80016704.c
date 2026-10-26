#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8 D_800DF998;
extern union X4_CdSectorBuffer D_800CF998;
extern struct X4_CdCompletionSlot D_800E01E8[16];
extern X4_RECT D_800E01E0;

void func_80016704(void) {
    u16* p;
    u8* t;
    u8* q;
    s32 o;

    D_800E01E0.w = 0x40;
    t = (u8*)D_800E01E8;
    o = D_800DF998 * 0xC;
    q = t + 4;
    t = 0;
    p = (u16*)(o + q);
    D_800E01E0.h = 0x10;
    D_800E01E0.x = p[1];
    D_800E01E0.y = p[0];
    LoadImage((M2C_UNK*)&D_800E01E0, (M2C_UNK*)D_800CF998.sectors[D_800DF998]);
}
