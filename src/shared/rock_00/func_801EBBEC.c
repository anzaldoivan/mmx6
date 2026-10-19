#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8003B114(s32);
extern void (*D_801F3778[])(void*);

void func_801EBBEC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        func_8003B114((s32)arg0);
        return;
    }
    func_80017A04((struct X4_AnimatedObj*)arg0);
    D_801F3778[M2C_FIELD(arg0, s8*, 6)](arg0);
}
