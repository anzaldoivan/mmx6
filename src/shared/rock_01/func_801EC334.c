#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002D5D0(void*);
s32 func_8003A33C(void*);
s32 func_8003A394(void*);
M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003B054(void*);
s32 func_8003B5B8(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_8003D394(void* arg0);
M2C_UNK func_801ECD54(void*, M2C_UNK);

void func_801EC334(u8* arg0) {
    s32 bits;
    s32 flag;

    bits = arg0[0x89];
    if (bits & 8) {
        arg0[0x8E] = 0;
        func_8003B054(arg0);
        return;
    }
    flag = ((s8*)arg0)[0xD3] != 0;
    if (!(bits & 3)) {
        flag = 1;
    }
    if (flag != 0) {
        arg0[0x8E] = 0;
        func_8003AFF4((s32)arg0);
        return;
    }
    if (func_8003A33C(arg0) != 0) {
        arg0[0x8E] = 0;
        return;
    }
    if (func_8003A394(arg0) != 0) {
        if (((s8*)arg0)[6] == 0) {
            arg0[6]++;
        } else {
            func_80017A04((struct X4_AnimatedObj*)arg0);
        }
        func_801ECD54(arg0, 0x1F);
        func_8002D5D0(arg0);
        func_8003D394(arg0);
        if (((s8*)arg0)[0x46] == 0) {
            arg0[0x8E] = 0;
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0xF);
            arg0[5] = 0xB;
            arg0[6] = 0;
        }
    } else {
        arg0[0x8E] = 0;
        func_8003B5B8(arg0);
    }
}
