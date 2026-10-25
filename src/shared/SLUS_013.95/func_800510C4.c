#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80031DA8(struct X4_MainObj*);      /* extern */
void func_80051104(struct X4_ItemObj* arg0); /* extern */

void func_800510C4(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) != 0x14) {
        ((void (*)())func_80031DA8)();
        func_80051104(arg0);
    }
}
