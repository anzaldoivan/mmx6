#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(M2C_UNK*);
extern void (*D_800FD490[])(void*);

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800FA76C(void* arg0) {
    F(s32, 0x18) = F(s32, 0x8);
    F(s32, 0x1C) = F(s32, 0xC);
    D_800FD490[F(s8, 0x4)](arg0);
    if (!(F(s8, 0x2) & 0xF0)) {
        func_8002F288((M2C_UNK*)arg0);
        F(u8, 0x71) = 0;
    }
}
