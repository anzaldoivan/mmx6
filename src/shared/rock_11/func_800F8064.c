#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800FD438[])(void*);

void func_800F8064(struct X4_BaseObj* self) {
    s32 v = M2C_FIELD(M2C_FIELD(self, void**, 0x80), s8*, 4);

    if (v != 1) {
        self->state = 6;
        self->on_screen = 0;
        return;
    }
    animate_object(self);
    (*(void (**)(void*))((self->action << 2) + (s32)D_800FD438))(self);
    if (check_enemy_hits(self) < 0) {
        func_80049E50(self);
        self->on_screen = 0;
        self->state = 6;
        self->action = 0;
        return;
    }
    func_80030ECC(self);
    if (is_off_screen(self, 0x20, 0x20) == v) {
        self->on_screen = 0;
        self->state = 6;
    }
}
