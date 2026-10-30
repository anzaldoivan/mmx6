#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern u8 D_800970B5;

static inline void func_800F5208_inl(struct X4_MainObj* obj, s32 v) {
    obj->unk5 = 1;
    ((u8*)obj)[0x47] = 0;
    obj->unk7C = 0x7F;
    obj->unk7E = 0x19;
    obj->invincibility_timer = 0x19;
    obj->unk42 &= 0x7FFF;
    func_8002CCB0(obj, v, 0x60);
}

void func_800F5208(struct X4_MainObj* self) {
    ((void (*)(void*, s32))set_animation)(self, 4);
    func_8003D308(0x14, D_800970B5);
    func_800F5208_inl(self, 0x60);
}
