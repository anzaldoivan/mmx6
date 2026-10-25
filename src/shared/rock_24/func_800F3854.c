#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern void* D_800F7800;
#define D_800F7800 ((struct X4_MainObj*)D_800F7800)

void func_800F3854(struct X4_MainObj* arg0) {
    struct X4_MainObj* p;
    s32 a;
    s32 b;

    p = *(struct X4_MainObj**)((u8*)arg0 + 0x7C);
    arg0->unk15 = p->unk15;
    arg0->x_pos.i.hi = p->x_pos.i.hi;
    arg0->y_pos.i.hi = p->y_pos.i.hi;
    if (p->state == 2) {
        arg0->state++;
        return;
    }
    switch (arg0->unk5) {
    case 0:
        if (p->unk7 > 0) {
            arg0->unk40 = 0x140;
            a = func_8002A47C(D_800F7800->id);
            b = func_8002A47C(D_800F7800->id);
            arg0->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            arg0->sprite_frames =
                (const u8*)(SPAD20 + *(s32*)(func_8002A47C(D_800F7800->id) * 4 +
                                             SPAD20));
            ((void (*)(void*, s32))func_800179A4)(arg0, 0x1E);
            func_8002CCB0(arg0, 0x20, 0x20);
            func_80017A04(arg0);
            {
                // !FAKE: depin: dropping it breaks the match (107/110)
                register s32 t asm("$2") = (u8)arg0->unk5 + 1;

                arg0->unk5 = t;
            }
        }
        break;
    case 1:
        if (arg0->animation_step.fields.relative_step == 0) {
            arg0->unk5--;
        }
        func_8002CCB0(arg0, 0x20, 0x20);
        func_80017A04(arg0);
        break;
    }
    func_8002D230(arg0);
}
#undef D_800F7800
