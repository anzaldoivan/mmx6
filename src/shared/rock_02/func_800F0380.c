#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern void (*D_800FB1E8[])(void*);

void func_800F0380(void* arg0) {
    D_800FB1E8[((s8*)arg0)[6]](arg0);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0xA0, 0xA0);
}
