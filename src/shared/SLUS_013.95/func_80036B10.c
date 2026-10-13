#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
s32 func_8003A33C(void*);              /* extern */
M2C_UNK func_8003AFF4(s32);            /* extern */
M2C_UNK func_8003B054(void*);          /* extern */
void func_8003B548(void*);             /* extern */
s32 func_8003E174(void*);              /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */

void func_80036B10(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        func_8003B054(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) == 0) {
        if (func_8003E174(arg0) != 0) {
            return;
        }
        if (M2C_FIELD(arg0, u8*, 0x89) & 3) {
            goto block_main;
        }
    }
    func_8003AFF4((s32)arg0);
    return;
block_main:
    if (func_8003A33C(arg0) == 0) {
        ((void (*)())func_80017A04)(arg0);
        if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
            if (M2C_FIELD(arg0, u8*, 0x89) & 1) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            M2C_FIELD(arg0, u8*, 0x45) &= 0x3F;
        }
        if (--M2C_FIELD(arg0, s8*, 0x8A) == 0) {
            func_8003B548(arg0);
            return;
        }
        func_8003F508(arg0, 0xD);
    }
}
