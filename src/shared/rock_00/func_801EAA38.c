#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
void* func_8002C32C();
s32 func_8003906C(void*);
s32 func_8003A2CC(void*);
M2C_UNK func_8003B114(s32);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void func_8003D18C(void* arg0);
void func_8003D394(void* arg0);

void func_801EAA38(u8* arg0) {
    s32 flag;
    u8 bits;
    u8* obj;
    s8 st;

    flag = 0;
    if (((s8*)arg0)[0xD3] != 0) {
        func_8003B114((s32)arg0);
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        goto end;
    }
    if (((s8*)arg0)[0x93] != 0) {
        if (((s8*)arg0)[6] == 0) {
            arg0[6]++;
            return;
        }
        func_80017A04((struct X4_AnimatedObj*)arg0);
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
        if (((s8*)arg0)[0x46] != 0) {
            return;
        }
        goto end;
    }
    bits = arg0[0x89];
    if (bits & 8) {
    end:
        func_8003B114((s32)arg0);
        return;
    }
    if ((bits & 4) && M2C_FIELD(arg0, s32*, 0x24) > 0) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (((s8*)arg0)[6] == 0) {
        arg0[6]++;
    } else {
        func_80017A04((struct X4_AnimatedObj*)arg0);
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
            flag = 1;
        }
    }
    if (arg0[0x45] & 0x40) {
        if (func_8003A2CC(arg0) != 0) {
            return;
        }
        if (func_8003906C(arg0) != 0) {
            return;
        }
    }
    func_8003D18C(arg0);
    func_8003D394(arg0);
    {
        register s32 t asm("$3") = ((s8*)arg0)[0x67];
        if (t > 0 && M2C_FIELD(arg0, s32*, 0x24) <= 0) {
            ((s8*)arg0)[0x67] = -1;
        }
    }
    if (flag != 0) {
        if (((s8*)arg0)[0x67] > 0) {
            func_8003BA04(arg0, 0xA);
            st = 6;
        } else {
            func_8003BA04(arg0, 0xB);
            st = 7;
        }
        arg0[5] = st;
        arg0[6] = 0;
    }
}
