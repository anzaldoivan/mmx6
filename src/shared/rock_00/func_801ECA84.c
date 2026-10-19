#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8003B114(s32);

void func_801ECA84(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        ((void (*)())func_8003B114)();
        return;
    }
    func_80017A04(arg0);
    if (M2C_FIELD(arg0, s8*, 0x99) == 0 || M2C_FIELD(arg0, s8*, 0x93) != 4) {
        func_8003B114((s32)arg0);
    }
}
