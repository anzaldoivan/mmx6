#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
M2C_UNK func_8002C9B0();
extern u32* D_80095098;
extern s8 D_800CCEED;

void func_800F95AC(struct X4_MainObj* self) {
    s32* p;
    s32 v;

    if (D_800CCEED >= 2) {
        ((M2C_UNK(*)())func_8002C9B0)();
        return;
    }
    self->unk40 = D_80095098[func_8002A47C(0x91)] >> 7;
    self->unk42 = ((func_8002A47C(0x91) * 4 + 0x20) % 16) |
                  (((func_8002A47C(0x91) + 8) / 4 + 0x1E0) << 6);
    v = func_8002A47C(0x91);
    p = SPAD20;
    v = p[v];
    self->unk16 = 0x13;
    self->animation_step.fields.frame_index = 0;
    self->state++;
    self->sprite_frames = (const u8*)p + v;
}
