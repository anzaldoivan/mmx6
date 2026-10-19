#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* func_8002C7F0(void);

M2C_UNK func_800F4534(void* arg0, M2C_UNK arg1) {
    void* obj;
    u8 b = arg1;

    obj = func_8002C7F0();
    {
        // !FAKE: pin the active-flag constant to the return register before the null test
        register s32 one asm("$2") = 1;
        if (obj != 0) {
            M2C_FIELD(obj, u8*, 0) = one;
            M2C_FIELD(obj, u8*, 1) = 0;
            M2C_FIELD(obj, u8*, 2) = b;
            M2C_FIELD(obj, u16*, 0xA) = 0;
            M2C_FIELD(obj, u16*, 0xE) = 0;
            M2C_FIELD(obj, void**, 0x5C) = arg0;
        }
    }
}
