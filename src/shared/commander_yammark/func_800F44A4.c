#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion();

void func_800F44A4(void* arg0) {
    if (D_8008EAFC == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        *((u8*)arg0 + 6) += 1;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
}
