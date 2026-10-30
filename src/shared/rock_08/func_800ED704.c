#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
extern void (*D_800F5900[])(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ED704(void* self) {
    F(s32, 0x18) = F(s32, 0x8);
    F(s32, 0x1C) = F(s32, 0xC);
    D_800F5900[F(s8, 0x5)](self);
    if (check_enemy_hits(self) < 0) {
        F(s32, 0x50) = 0;
        F(s16, 0x7C) = 0x3C;
        F(s8, 0x5) = 2;
        return;
    }
    func_80030ECC(self);
    if (F(s8, 0x5) != 3) {
        func_8002CCB0((struct X4_BaseObj*)self, 0x20, 0x20);
        return;
    }
    F(s8, 0x3) = 0;
}
