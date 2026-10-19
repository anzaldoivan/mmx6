#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern u8 D_800C4560;

void func_800FA384(void* arg0) {
    s32 t;
    s32 r;
    s32 base;

    ((void (*)())func_80017A04)();
    M2C_FIELD(arg0, u16*, 0x8C) = (u16)(M2C_FIELD(arg0, u16*, 0x8C) + 1);
    if (M2C_FIELD(arg0, s8*, 2) == 5) {
        t = (func_8002A47C(0x3C) * 4) + 0x24;
        r = (func_8002A47C(0x3C) << 7) + 0x380;
        base = SPAD28;
        ((void (*)())func_8002B54C)(base + r, base + (t << 5), 0x40,
                                    M2C_FIELD(arg0, s16*, 0x8C));
        D_800C4560 |= 1;
    }
    if (M2C_FIELD(arg0, s16*, 0x8C) >= 0x1F) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
