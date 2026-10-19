#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* func_8002C7F0(void);

void func_800EA278(u8* arg0, s32 arg1) {
    u8 b = arg1;
    void* obj;

    obj = func_8002C7F0();
    {
        s32 one = 1;
        if (obj != 0) {
            s32 id = 0xC;
            M2C_FIELD(obj, u8*, 0) = one;
            M2C_FIELD(obj, u8*, 1) = id;
            M2C_FIELD(obj, u8*, 2) = b;
            M2C_FIELD(obj, u8**, 0x5C) = arg0;
        }
    }
}
