#include "common.h"
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

extern struct X4_PlayerObj D_800970A0;
s32 func_800EF4D4(u32);
void func_800EF76C(void*, s32);

void func_800EF620(void* arg0) {
    u16 i;

    for (i = 0; i < 8; i++) {
        if (func_800EF4D4(i) != 0) {
            u8* p = (u8*)&D_800970A0;
            p[0x150] = 1;
            if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
                M2C_FIELD(arg0, s16*, 0x7C) = 5;
                func_800EF76C(arg0, 1);
            }
            return;
        }
    }
    {
        u8* p = (u8*)&D_800970A0;
        p[0x150] = 0;
    }
}
