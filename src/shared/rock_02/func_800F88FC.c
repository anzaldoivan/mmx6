#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK func_8002B54C(M2C_UNK*, M2C_UNK*, M2C_UNK, u16);
extern u8 D_800C4560;

void func_800F88FC(void* arg0) {
    s32 base;

    M2C_FIELD(arg0, u16*, 0x90) = M2C_FIELD(arg0, u16*, 0x90) + 1;
    base = SPAD28;
    ((void (*)(M2C_UNK*, M2C_UNK*, M2C_UNK, s32))func_8002B54C)(
        (M2C_UNK*)(base + 0xB80), (M2C_UNK*)(base + 0xB00), 0x40,
        M2C_FIELD(arg0, s16*, 0x90));
    D_800C4560 |= 1;
    if (M2C_FIELD(arg0, s16*, 0x90) >= 0x1F) {
        M2C_FIELD(arg0, u8*, 4) = 2;
    }
}
