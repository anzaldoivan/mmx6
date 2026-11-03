#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern void (*D_800F7C30[])(void*);

void func_800F4674(void* arg0) {
    D_800F7C30[((s8*)arg0)[6]](arg0);
    ((void (*)(void*))animate_object)(arg0);
    ((void (*)(void*))apply_object_motion)(arg0);
    ((void (*)(void*, s32, s32))func_8002CCB0)(arg0, 0x40, 0x40);
}
