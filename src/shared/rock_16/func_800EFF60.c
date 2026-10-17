#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCEFB;
extern u16 D_800F16C8[][2];

void func_800EFF60(struct X4_AnimatedObj* self) {
    if (self->unk2 != 0) {
        func_800179D0(self, 5, D_800CCED0.character_state.bytes[5]);
        self->x_pos.i.hi =
            D_800F16C8[D_800CCED0.character_state.bytes[5]][0] + 0x782;
        self->y_pos.i.hi =
            D_800F16C8[D_800CCED0.character_state.bytes[5]][1] + 0xB1;
    } else {
        // !FAKE: depin: dropping it breaks the match (63/66)
        register s32 a asm("$2");
        // !FAKE: depin: dropping it breaks the match (29/66)
        register s32 b asm("$3");
        func_800179D0(self, 4, D_800CCEFB);
        a = 0x732;
        b = 0x17;
        self->x_pos.i.hi = a;
        self->y_pos.i.hi = b;
    }
    if (D_800971F8[self->bg_offset].x_pos.i.hi < 0x400) {
        self->x_pos.i.hi -= 0x600;
    }
    func_8002CCB0(self, 0x60, 0x10);
}
