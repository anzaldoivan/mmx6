#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(void*);
extern s16 D_800F4480;

void func_800F26D4(u8* arg0) {
    ((void (*)(void*))move_object)(arg0);
    ((void (*)(void*))animate_object)(arg0);
    if (D_800F4480 + 0x460 < *(s16*)(arg0 + 0xE)) {
        *(s32*)(arg0 + 0x24) = 0;
        *(u8*)(arg0 + 6) = *(u8*)(arg0 + 6) + 1;
    }
}
