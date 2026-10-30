#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
void* func_8002C32C();
s32 func_80039C40(void*);
s32 func_80039C9C(void*);
M2C_UNK end_dash(s32);

void func_801EBAE0(u8* arg0) {
    u8* obj;

    if (((s8*)arg0)[0xD3] != 0) {
        ((void (*)())end_dash)();
        return;
    }
    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        // !FAKE: goto: shared call block inlined where retail lays it (C0115)
        goto call;
    }
    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[0x45] & 0x80) {
        arg0[0x45] &= 0x7F;
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x32;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
            obj[0x15] = arg0[0x15];
        }
    }
    if (((s8*)arg0)[0x46] == 0) {
    call:
        end_dash((s32)arg0);
        return;
    }
    if (((s8*)arg0)[0x93] == 0 && (arg0[0x45] & 0x40) &&
        func_80039C40(arg0) == 0) {
        func_80039C9C(arg0);
    }
}
