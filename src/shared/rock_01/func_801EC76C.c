#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002FE30(void*);
M2C_UNK func_8003AF1C(void*);
M2C_UNK func_801ECD54(void*, M2C_UNK);

#define U16(o) (*(u16*)(p + (o)))

void func_801EC76C(s8* p) {
    s32 v;

    if (p[6] == 0) {
        p[6]++;
    } else {
        func_80017A04(p);
        func_801ECD54(p, (s8)((p[0x45] & 0x7F) + 0x26));
    }
    if (U16(0x80) & 2) {
        p[0x15] = 0;
    }
    if (U16(0x80) & 1) {
        p[0x15] = 0x40;
    }
    if (p[0xD3] == 0) {
        p[0x8E] = 0;
        if (U16(0x80) & 0x80) {
            func_8003AF1C(p);
            return;
        }
        p[0x8E] = 1;
    }
    if (p[0x46] == 0) {
        p[0x8E] = 0;
        v = func_8002FE30(p);
        if (v == 0x2E) {
            v = 0x1B;
        } else {
            v = 0x1C;
        }
        p[5] = v;
        p[6] = 1;
    }
}
