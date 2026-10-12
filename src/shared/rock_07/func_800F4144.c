#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002A47C(s32);
extern u16 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)

#define SP_20 (*(s8**)0x1F800020)
#define SP_9C (*(s8**)0x1F80009C)

void func_800F4144(void* arg0) {
    s32 a;
    s32 b;
    s32 c;
    s8* p;

    M2C_FIELD(arg0, s16*, 0x40) = 0x540;
    if (D_800CCEDC != 0xC) {
        a = func_8002A47C(M2C_FIELD(arg0, s8*, 0x1));
        b = func_8002A47C(M2C_FIELD(arg0, s8*, 0x1));
        M2C_FIELD(arg0, s16*, 0x42) =
            (((a + 1) * 4 + 0x20) % 16) | (((b + 9) / 4 + 0x1E0) << 6);
        c = func_8002A47C(M2C_FIELD(arg0, s8*, 0x1));
        M2C_FIELD(arg0, s8**, 0x3C) = SP_20 + ((s32*)SP_20)[c + 1];
    } else {
        p = SP_9C;
        c = ((s32*)p)[1];
        M2C_FIELD(arg0, s16*, 0x42) = 0x794C;
        M2C_FIELD(arg0, s8**, 0x3C) = p + c;
    }
}

#undef D_800CCEDC
