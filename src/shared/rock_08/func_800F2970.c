#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK move_object(void*);

void func_800F2970(void* arg0) {
    u8* obj = arg0;

    animate_object(obj);
    ((void (*)(void*))move_object)(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[6]++;
    }
}
