#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern s32 D_800FE290;
extern void* D_800FE298;

#define PARENT ((struct X4_MainObj*)D_800FE298)

void func_800FB1F0(struct X4_MainObj* self) {
    s32 d;
    struct X4_MainObj* p;

    if (D_800FE290 != 0) {
        self->state++;
        return;
    }
    self->unk15 = PARENT->unk15;
    if (self->unk15 == 0) {
        self->x_pos.i.hi = PARENT->x_pos.i.hi + 0x1E;
    } else {
        self->x_pos.i.hi = PARENT->x_pos.i.hi - 0x1E;
    }
    p = PARENT;
    self->y_pos.i.hi = p->y_pos.i.hi + 8;
    switch (self->unk5) {
    case 0:
        if (M2C_FIELD(p, s8*, 0x45) == 9) {
            ((void (*)(void*, s32))set_animation)(self, 9);
            self->unk5++;
        }
        break;
    case 1:
        d = p->x_speed;
        if ((d < 0 ? -d : d) != 0x42000 || M2C_FIELD(self, s8*, 0x46) == 0) {
            self->unk5--;
        }
        func_8002CCB0(self, 0x20, 0x20);
        func_80017A04(self);
        move_object(self);
        break;
    }
}

#undef PARENT
