#include "common.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s8 D_800CCEED;

void func_800F96AC(void* arg0) {
    func_8002CCB0(arg0, 0x30, 0x20);
    if (D_800CCEED >= 2) {
        clear_object_slot(arg0);
    }
}
