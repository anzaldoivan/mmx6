#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_80078E08[];
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_8003C4EC(struct X4_PlayerObj* self);

void func_80051ED4(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* p = &D_800970A0;
    s8 t;
    s32 x = arg0->x_pos.val;

    *((u8*)p + 0xE2) = 4;
    p->x_pos.val = x;
    func_800179A4(arg0, 0xD);
    t = arg0->unk2;
    if (t == 8) {
        if (p->unk2 != 0) {
            D_800CCED0.unk5F |= 0x20;
            func_8003C4EC(p);
        }
    } else {
        u8* e = (u8*)&D_800CCED0;
        e[0x69] |= D_80078E08[t];
    }
    D_800CCED0.unk16 = 0;
    D_800CCED0.unk12 = 0;
    D_800CCED0.unk13 = 0;
    D_800CCED0.unk17 = 0;
    arg0->unk5++;
}
