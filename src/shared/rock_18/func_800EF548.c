#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBFC(void*, u8, s16, s16);
extern s16 D_8006D624[];
extern struct X4_EngineObj g_playthrough_state;

void func_800EF548(struct X4_BaseObj* self) {
    u8* e = (u8*)&g_playthrough_state;
    s16 i;
    s16 v = ((s16*)&g_playthrough_state)[M2C_FIELD(e, s8*, 0x38) + 0x69];

    for (i = 0; i < 8; i++) {
        if (v >= D_8006D624[i]) {
            u8* f = (u8*)&g_playthrough_state;
            *(M2C_FIELD(f, s8*, 0x38) + ((u8*)&g_playthrough_state + 0x8D)) = i;
            if (i < 4) {
                func_800EFBFC(self, i - 0x7C, self->x_pos.i.hi - 4,
                              self->y_pos.i.hi);
            } else {
                func_800EFBFC(self, i - 0x7C, self->x_pos.i.hi,
                              self->y_pos.i.hi);
            }
            self->state = 2;
            return;
        }
    }
    self->state = 2;
}
