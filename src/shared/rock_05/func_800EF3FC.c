#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_9C (*(s32**)0x1F80009C)
#define SCRATCH_20 (*(s32**)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800F4330;

void func_800EF3FC(struct X4_MainObj* self) {
    s32 a;
    s32 b;

    func_8003D308(0x14, D_800970A0.unk15);
    func_80029478(0, 0, 0);
    func_80016C48(2, 3, self);
    self->unk40 = 0x440;
    self->unk42 &= 0x7FFF;
    if (D_800CCED0.stage == 0xC) {
        s32* p = SCRATCH_9C;
        s32 o = p[1];
        self->unk42 = 0x794C;
        self->sprite_frames = (u8*)p + o;
    } else {
        a = func_8002A47C(self->id);
        b = func_8002A47C(self->id);
        a = (a + 1) * 4;
        self->unk42 = (a + 0x20) % 16 | (((b + 9) / 4 + 0x1E0) << 6);
        self->sprite_frames =
            (u8*)SCRATCH_20 + SCRATCH_20[func_8002A47C(self->id) + 1];
    }
    self->animation_table = &D_800F4330;
    func_800179A4(self, 0);
    {
        register s32 c7f asm("$2") = 0x7F;
        self->unk7C = c7f;
    }
    {
        register s32 c19 asm("$3") = 0x19;
        self->unk7E = c19;
        self->invincibility_timer = c19;
    }
    self->on_screen = 1;
    self->unk5 = 1;
}
