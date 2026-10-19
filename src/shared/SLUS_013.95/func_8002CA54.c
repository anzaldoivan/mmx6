#include "common.h"
#define M2C_UNK s32

#define CA54_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002C9B0(void* arg0);

M2C_UNK func_8002CA54(void* arg0) {
    u8* p;
    u8* q;
    u8 v;

    p = CA54_FIELD(arg0, u8**, 0x10);
    if (p != 0) {
        p[0] &= 0x70;
        q = CA54_FIELD(arg0, u8**, 0x10);
        v = q[3];
        if ((v & 0xF0) == 0x10) {
            q[3] = v & 0xF;
        }
    }
    func_8002C9B0(arg0);
}

#undef CA54_FIELD
