#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
s32 func_8002CFB0(void* arg);          /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
M2C_UNK func_8003CDF0();               /* extern */
M2C_UNK func_8003D10C(void*);          /* extern */

void func_80037FD4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        ((M2C_UNK(*)())func_80017A04)();
        func_8002CFB0(arg0);
        if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            func_8003BA04(arg0, 0xB);
            M2C_FIELD(arg0, s8*, 0x67) = -1;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
        }
    } else {
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            func_8003CDF0(arg0);
            func_8003D10C(arg0);
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            M2C_FIELD(arg0, s8*, 0xD0) = -1;
            M2C_FIELD(arg0, s8*, 5) = 0x14;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
        ((M2C_UNK(*)())func_80017A04)(arg0);
        func_8002CFB0(arg0);
    }
}
