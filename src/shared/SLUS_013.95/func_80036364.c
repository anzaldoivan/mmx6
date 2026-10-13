#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_80017A04();                        /* extern */
s32 func_8002CFB0(void* arg);                   /* extern */
s32 func_8003A628(void*);                       /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK);          /* extern */

void func_80036364(void* arg0) {
    s8 temp_v1;

    ((void (*)())func_80017A04)(arg0);
    func_8002CFB0(arg0);
    temp_v1 = M2C_FIELD(arg0, s8*, 6);
    if (temp_v1 == 2) {
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            func_8003A628(arg0);
        }
    } else if (temp_v1 == 1) {
        if (M2C_FIELD(arg0, s32*, 0x20) <= 0) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0x52);
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    } else if (temp_v1 == 0) {
        if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
            M2C_FIELD(arg0, u8*, 0x45) = M2C_FIELD(arg0, u8*, 0x45) & 0x3F;
            func_80016C48(1, 1, arg0);
        }
        if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0xB);
            M2C_FIELD(arg0, s8*, 0x67) = -1;
        }
        if ((M2C_FIELD(arg0, s8*, 0x67) == -1) &&
            (M2C_FIELD(arg0, u8*, 0x89) & 8)) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0x51);
            M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            M2C_FIELD(arg0, s32*, 0x28) = -0x1000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x2C) = 0;
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}
