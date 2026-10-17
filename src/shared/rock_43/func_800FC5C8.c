#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_8003C6A4(void* arg0);
extern s16 D_800970AA;

void func_800FC5C8(struct X4_MainObj* self) {
    if (M2C_FIELD(self, s8*, 0x45) == 1) {
        s32 d;

        M2C_FIELD(self, s8*, 0x45) = 0;
        d = D_800970AA;
        if (self->x_pos.i.hi < d) {
            self->unk15 = 0x40;
        } else {
            self->unk15 = 0;
        }
        if (self->unk15 == 0) {
            self->x_speed = 0xFFFBE000;
        } else {
            self->x_speed = 0x42000;
        }
        func_80016C48(2, 0x85, self);
        func_80016C48(2, 0x97, self);
        func_8003C6A4(self);
    }
    if (M2C_FIELD(self, s8*, 0x45) == 2) {
        self->unk6++;
    }
    func_8002CCB0(self, 0x40, 0x40);
    func_80017A04(self);
    func_8002D230(self);
}
