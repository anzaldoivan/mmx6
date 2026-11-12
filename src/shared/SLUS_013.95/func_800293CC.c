#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800972A0;
extern void (*D_80071EB0[])(void*);

void func_800293CC(void) {
    void* p = &D_800972A0;

    if (M2C_FIELD(p, s8*, 0x44) != 0 && D_8009716C == 0) {
        M2C_FIELD(p, s32*, 0x14) = M2C_FIELD(p, s32*, 0x8);
        M2C_FIELD(p, s32*, 0x18) = M2C_FIELD(p, s32*, 0xC);
        D_80071EB0[M2C_FIELD(p, s8*, 0x4)](p);
    }
}
