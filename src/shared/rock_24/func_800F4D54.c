#include "common.h"

#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
extern void (*D_800F7640[])(void*);

void func_800F4D54(s8* arg0) {
    D_800F7640[arg0[6]](arg0);
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}
