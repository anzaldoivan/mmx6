#include "common.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();

void func_800ECB00(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7E) == 0) {
        clear_object_slot();
    }
}
