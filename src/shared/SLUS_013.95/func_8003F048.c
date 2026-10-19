#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003DBDC(void* self);
void func_8003DD6C(void* self);
M2C_UNK func_8003DF58(void*);
M2C_UNK func_8003F0BC(void*);

void func_8003F048(void* arg0) {
    s8 temp_s0;

    if (M2C_FIELD(arg0, s8*, 2) != 0) {
        func_8003DBDC(arg0);
        return;
    }
    temp_s0 = M2C_FIELD(arg0, s8*, 0x93);
    func_8003DD6C(arg0);
    func_8003DF58(arg0);
    {
        // !FAKE: retail reads the re-loaded byte into the first return register
        register s32 cur asm("$2") = M2C_FIELD(arg0, s8*, 0x93);
        if (temp_s0 != cur) {
            func_8003F0BC(arg0);
        }
    }
}
