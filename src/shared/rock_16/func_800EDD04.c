#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CB50();
extern struct X4_EngineObj g_playthrough_state;

void func_800EDD04(struct X4_AnimatedObj* self) {
    if ((*(s32*)&g_playthrough_state & 0xFFFF00) == 0x400) {
        set_animation(self, 0);
        self->unk6 = 0;
        func_8002CB50(self);
    }
}
