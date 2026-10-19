#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
s32 func_80065944(s32);
s32 func_80065A14(s32);

extern s32 D_800F6738;
extern s32 D_800F673C;

#define U8(o) M2C_FIELD(self, u8*, o)
#define S32(o) M2C_FIELD(self, s32*, o)
#define PTR(o) M2C_FIELD(self, void**, o)

void func_800EF8C8(void* self) {
    s32 a;
    s32 t;
    s32 u;

    a = (func_8002D2D4() * 8) & 0x7FF;
    t = func_80065A14(a) << 4;
    S32(0x20) = t * 4 + t;
    u = func_80065944(a) << 4;
    S32(0x24) = u * 4 + u;
    PTR(0x50) = &D_800F6738;
    PTR(0x54) = &D_800F673C;
    U8(6)++;
}
