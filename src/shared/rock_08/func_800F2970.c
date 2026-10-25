#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK move_object(void*);

void func_800F2970(void* arg0) {
    u8* obj = arg0;

    func_80017A04(obj);
    ((void (*)(void*))move_object)(obj);
    if (--*(s16*)(obj + 0x7C) == 0) {
        obj[6]++;
    }
}
