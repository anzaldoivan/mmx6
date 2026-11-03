#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

void func_800ED460(void* arg0) {
    func_8002CCB0(arg0, 0x80, 0x20);
    if (D_800CCEED >= 2) {
        clear_object_slot(arg0);
    }
}
