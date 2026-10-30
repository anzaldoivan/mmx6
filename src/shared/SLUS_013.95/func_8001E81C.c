#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0); /* extern */
M2C_UNK func_80013DE8();       /* extern */

void func_8001E81C(void* arg0) {
    s8* p;
    u32 i;

    M2C_FIELD(arg0, s8*, 0) = 0xC;
    i = 0;
    p = (s8*)arg0 + 0x26;
    do {
        p[i] = 0;
        i++;
    } while (i < 0x10);
    M2C_FIELD(arg0, s8*, 0xC) = 0xF;
    M2C_FIELD(arg0, s8*, 0xD) = 0;
    M2C_FIELD(arg0, s8*, 0x1D) = 0;
    M2C_FIELD(arg0, s8*, 0x1F) = 0;
    M2C_FIELD(arg0, s8*, 0x24) = 0;
    func_80013DE8();
    set_resolution(1);
}
