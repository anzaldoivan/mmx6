#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(void*);
extern s32 D_800FE290;
extern s32 D_800FE294;

void func_800FDAAC(struct X4_MainObj* self) {
    if (D_800FE290 != 0 || D_800FE294 != 0) {
        self->state++;
        return;
    }
    if (++M2C_FIELD(self, s32*, 0x8C) == 0x12) {
        self->state++;
    }
    func_8002CCB0(self, 0x20, 0x20);
    func_80017A04(self);
    move_object(self);
}
