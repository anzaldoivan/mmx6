#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
void* func_8002C32C();
M2C_UNK func_8002D5D0(void*);
s32 func_8003A33C(void*);
s32 func_8003A394(void*);
M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003B114(s32);
s32 func_8003B5B8(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_8003D394(void* arg0);
s32 func_8003E174(void*);

void func_801EACA0(u8* arg0) {
    u8* obj;
    s32 bits;
    s32 flag;

    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        ((void (*)())func_8003B114)();
        return;
    }
    if (((s8*)arg0)[0x93] != 0) {
        if (((s8*)arg0)[6] == 0) {
            arg0[6]++;
        } else {
            func_80017A04((struct X4_AnimatedObj*)arg0);
        }
        if (((s8*)arg0)[0x45] & 0x80) {
            arg0[0x45] &= 0x7F;
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x33;
                obj[0x14] = arg0[0x14];
                M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
                obj[0x15] = arg0[0x15];
            }
        }
        if (((s8*)arg0)[0x46] == 0) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0xF);
            arg0[5] = 0xB;
            arg0[6] = 0;
        }
    } else {
        bits = arg0[0x89];
        if (bits & 8) {
            func_8003B114((s32)arg0);
            return;
        }
        flag = ((s8*)arg0)[0xD3] != 0;
        if (!(bits & 3)) {
            flag = 1;
        }
        if (flag != 0) {
            func_8003AFF4((s32)arg0);
            return;
        }
        if (func_8003A33C(arg0) == 0) {
            if (func_8003A394(arg0) != 0) {
                if (((s8*)arg0)[6] == 0) {
                    arg0[6]++;
                } else {
                    func_80017A04((struct X4_AnimatedObj*)arg0);
                }
                if (((s8*)arg0)[0x45] & 0x80) {
                    arg0[0x45] &= 0x7F;
                    obj = func_8002C32C();
                    if (obj != 0) {
                        obj[0] = 1;
                        obj[1] = 0x33;
                        obj[0x14] = arg0[0x14];
                        M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
                        obj[0x15] = arg0[0x15];
                    }
                }
                if (!(arg0[0x45] & 0x40) || func_8003E174(arg0) == 0) {
                    func_8002D5D0(arg0);
                    func_8003D394(arg0);
                    bits = ((s8*)arg0)[0x46];
                    if (bits == 0) {
                        ((void (*)(void*, s32))func_8003BA04)(arg0, 0xF);
                        arg0[5] = 0xB;
                        arg0[6] = 0;
                    }
                }
            } else {
                func_8003B5B8(arg0);
            }
        }
    }
}
