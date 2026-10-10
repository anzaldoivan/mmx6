#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(s32*)0x1F800028)

s32 func_8002A47C(s32);
M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern u8 D_800C4560;

void func_800F85C4(void* arg0) {
    s32 a;
    s32 b;
    s32 base;

    M2C_FIELD(arg0, u16*, 0x90) = M2C_FIELD(arg0, u16*, 0x90) + 1;
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 2) == 0) {
        b = func_8002A47C(0x37) * 4 + 0x20;
        a = func_8002A47C(0x37) * 4 + 0x24;
    } else {
        b = 0x58;
        a = 0x5C;
    }
    base = SPAD28;
    ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
        (M2C_UNK*)(base + a * 32), (M2C_UNK*)(base + b * 32), 0x40,
        M2C_FIELD(arg0, s16*, 0x90));
    D_800C4560 |= 1;
    if (M2C_FIELD(arg0, s16*, 0x90) >= 0x1F) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
