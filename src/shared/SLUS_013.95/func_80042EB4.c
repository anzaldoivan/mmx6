#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

struct X4_QuadObj* func_8002C7F0(void);

void func_80042EB4(void* arg0, u8 arg1, s32 arg2) {
    struct X4_QuadObj* q;

    q = func_8002C7F0();
    if (q != 0) {
        M2C_FIELD(q, u8*, 0) = 1;
        M2C_FIELD(q, u8*, 1) = 0xD;
        M2C_FIELD(q, u8*, 2) = arg1;
        M2C_FIELD(q, void**, 0x5C) = arg0;
        M2C_FIELD(q, s16*, 0x46) = arg2;
        M2C_FIELD(q, u8*, 7) = M2C_FIELD(arg0, u8*, 6);
    }
}
