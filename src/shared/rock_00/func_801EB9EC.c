#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
void* func_8002C32C();
M2C_UNK end_dash(s32);
void func_801EC6D0(void*, s32);

void func_801EB9EC(u8* arg0) {
    u8* obj;

    if (((s8*)arg0)[0xD3] != 0) {
        ((M2C_UNK(*)())end_dash)();
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        end_dash((s32)arg0);
        return;
    }
    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[7] == 0) {
        func_801EC6D0(arg0, 0x32);
    } else {
        func_801EC6D0(arg0, 0x33);
    }
    if (arg0[0x45] & 1) {
        arg0[0x45] &= 0xFE;
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2E;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
        }
    }
    if (((s8*)arg0)[0x46] == 0) {
        end_dash((s32)arg0);
    }
}
