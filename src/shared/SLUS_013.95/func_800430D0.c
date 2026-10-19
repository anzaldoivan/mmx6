#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();                                         /* extern */
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2); /* extern */
extern void (*D_800760E0[])(void*);

void func_800430D0(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x50), s8*, 4) != 1) {
        M2C_FIELD(arg0, u8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
        return;
    }
    func_8002CCB0(arg0, 0x10, 0x10);
    D_800760E0[M2C_FIELD(arg0, s8*, 5)](arg0);
    ((void (*)())func_80017A04)(arg0);
}
