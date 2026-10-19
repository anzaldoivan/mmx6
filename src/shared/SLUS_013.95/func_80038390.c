#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_80039FFC(void*);
M2C_UNK func_8003B30C(void*);
M2C_UNK func_8003D26C(void*);

void func_80038390(void* arg0) {
    u8 v;

    ((M2C_UNK(*)())func_80017A04)();
    if (func_80039FFC(arg0) != 0) {
        ((void (*)(void*))func_8003B30C)(arg0);
        M2C_FIELD(arg0, u8*, 5) = 0xD;
        return;
    }
    v = M2C_FIELD(arg0, u8*, 0x45);
    if (v & 0x40) {
        M2C_FIELD(arg0, u8*, 0x45) = v & 0x3F;
        func_8003D26C(arg0);
    }
}
