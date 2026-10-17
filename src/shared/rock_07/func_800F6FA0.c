#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(M2C_UNK*); /* extern */
extern void (*D_800F97A4[])(void*);

void func_800F6FA0(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    M2C_FIELD(arg0, u8*, 0x95) =
        M2C_FIELD(arg0, u8*, 0x70) | M2C_FIELD(arg0, u8*, 0x71);
    D_800F97A4[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    if (!(M2C_FIELD(arg0, s8*, 0x2) & 0xF0)) {
        func_8002F288(arg0);
        M2C_FIELD(arg0, u8*, 0x71) = 0;
    }
}
