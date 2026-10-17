#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003B114(s32);
void func_8003CF54(void*, s32);
M2C_UNK func_8003D3F8(M2C_UNK, s8, M2C_UNK, void*);
M2C_UNK func_801EC678(); /* extern */
extern s8 D_800CCEEC;

void func_801EC514(void* arg0) {
    if ((func_801EC678() != 0) && (M2C_FIELD(arg0, u8*, 0x45) & 0x40)) {
        if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
            M2C_FIELD(arg0, s8*, 0x7A) = 0;
        }
        M2C_FIELD(arg0, s8*, 0xE0) = 0;
        D_800CCEEC = 0;
        func_8003B114((s32)arg0);
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x45) & 0x20) {
        M2C_FIELD(arg0, u8*, 0x45) = 0;
        func_8003D3F8(1, 0x16, 0, 0);
        func_8003CF54(arg0, 0x49);
        func_80016C48(1, 0x12, arg0);
        if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x80000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFF80000;
        }
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
