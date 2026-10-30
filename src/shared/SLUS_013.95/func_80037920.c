#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80037B10(void* arg0);    /* extern */
M2C_UNK func_8003AFF4(s32);        /* extern */
void check_low_health(void* arg0); /* extern */
void func_8003D394(void* arg0);    /* extern */

void func_80037920(void* arg0) {
    func_80037B10(arg0);
    func_8003D394(arg0);
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) += 1;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x61) == 0x3C) {
        ((void (*)(s32))func_8003AFF4)((s32)arg0);
        if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
            M2C_FIELD(arg0, u8*, 0xA4) = 0;
            M2C_FIELD(arg0, u8*, 0x61) = 0;
            return;
        }
        check_low_health(arg0);
        M2C_FIELD(arg0, s8*, 0xA4) = -1;
    }
}
